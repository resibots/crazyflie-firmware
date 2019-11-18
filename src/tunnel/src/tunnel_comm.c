/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_comm.c - Handles the drone's communication routines and 
 *                 New CRTP requests coming from the base.
 */

#include "tunnel_comm.h"
#include "tunnel_config.h"

#include "tunnel_parameters.h"
#include "tunnel_signal.h"
#include "tunnel_relay.h"
#include "tunnel_ping.h"

#include "tunnel.h"
#include "tunnel_behavior.h"
#include "tunnel_commander.h"
#include "pm.h"

#define DEBUG_MODULE "COM"
#include "debug.h"
#include "led.h"
#include "ledseq.h"
#include "crtp.h"

static bool isInit = false;
static unsigned long statusPrevTime = 0;
static TunnelStatus currentStatus;

typedef enum {
  CRTP_TUNNEL_COMMAND_TAKE_OFF       = 0x00, // Start flying and do our thing!
  CRTP_TUNNEL_COMMAND_SET_BEHAVIOR   = 0x01, // Set a specific behavior while the drone is flying
  CRTP_TUNNEL_COMMAND_SET_MODE       = 0x02, // Set this drone's mode (will not propagate to other drones)
  CRTP_TUNNEL_COMMAND_RTH            = 0x03, // Return to home automatically
  CRTP_TUNNEL_COMMAND_LAND           = 0x04, // Land no matter where we are (e.g. to manually save battery)
  CRTP_TUNNEL_COMMAND_CUT_MOTORS     = 0x05, // Cut the motors and return to Idle state (for emergencies or tests)
} CRTPTunnelCommand;

void refreshDroneStatus() {
  // Calculate battery level
  uint8_t batteryVt = BATTERY_RES * (pmGetBatteryVoltage() - BATTERY_MIN) / (BATTERY_MAX - BATTERY_MIN);
  if(!pmIsDischarging() || batteryVt > 0x0F) batteryVt = 0x0F;
  currentStatus.batteryVoltage = batteryVt;

  // Update status bits
  currentStatus.isHead = tunnelGetDroneRole() == DRONE_ROLE_HEAD ? 1 : 0;
  currentStatus.isLeaderConnected   = tunnelIsDroneConnected(getLeaderID());
  currentStatus.isFollowerConnected = tunnelIsDroneConnected(getFollowerID());
  currentStatus.isBaseConnected     = tunnelIsBaseConnected();

  currentStatus.droneState = tunnelGetDroneState();
  currentStatus.currentBehavior = tunnelGetCurrentBehavior();
}

// Returns the size used and fills general information about the drone
uint8_t appendStatusMessage(uint8_t *pkData) {
  // Send battery level, Drone role, Drone state, Current behavior
  memcpy(pkData, &currentStatus, sizeof(TunnelStatus));
  return sizeof(TunnelStatus);
}

static void broadcastStatus() {
  P2PPacket p_status;
  p_status.txdest = P2P_BROADCAST_ID;
  p_status.port = P2P_PORT_STATUS;

  // Generate status info and add it to the message
  p_status.size = appendStatusMessage(p_status.txdata);

  // Report status to PC while at it
#ifdef PRINT_TUNNEL_STATUS
  DEBUG_PRINT("STATUS %02x%02x\n", p_status.txdata[0], p_status.txdata[1]);
#endif

  p2pSendPacket(&p_status);
}

void tunnelCommUpdate() {
  // Handle ping routines
  tunnelPingUpdate();

  // Broadcast our own status regularly (don't pollute the air traffic with inactive drones)
  refreshDroneStatus();
  if(tunnelGetDroneState() != DRONE_STATE_INACTIVE && timerElapsed(&statusPrevTime, 200))
    broadcastStatus();
}

// Drone randomly crashes if we use a switch, no idea why...
void processIncomingCRTPPacket(CRTPTunnelPacket* p) {
  if(p->channel == CRTP_TUNNEL_CHANNEL_PING)
    crtpTunnelPingHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_PARAM)
    crtpTunnelParametersHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_COMMANDER)
    crtpTunnelCommanderHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_COMMAND) {
    uint8_t command = p->dronedata[0];
    if(command == CRTP_TUNNEL_COMMAND_TAKE_OFF)
      tunnelSetDroneState(DRONE_STATE_FLYING);
    else if(command == CRTP_TUNNEL_COMMAND_SET_BEHAVIOR)
      tunnelSetBehavior(p->dronedata[1]);
    else if(command == CRTP_TUNNEL_COMMAND_SET_MODE)
      tunnelSetDroneMode((p->dronedata[1] == DRONE_MODE_AUTO) ? DRONE_MODE_AUTO : DRONE_MODE_MANUAL);
    else if(command == CRTP_TUNNEL_COMMAND_LAND)
      if(tunnelGetCurrentBehavior() != TUNNEL_BEHAVIOR_IDLE)
        tunnelSetBehavior(TUNNEL_BEHAVIOR_LAND);
    else if(command == CRTP_TUNNEL_COMMAND_RTH)
      ;//TODO implement RTH
    else if(command == CRTP_TUNNEL_COMMAND_CUT_MOTORS)
      tunnelSetDroneState(DRONE_STATE_IDLE);
  }
}

void crtpTunnelHandler(CRTPTunnelPacket *p) {
  p->direction = 1; // mark the packet as base-to-drone
  p->size--;

  if(p->destination == getDroneId())
    processIncomingCRTPPacket(p);
  else
    tunnelSendCRTPPacketToDrone(p);
}

void tunnelCommInit() {
  if(isInit) return;

  tunnelParametersInit();
  tunnelSignalInit();
  tunnelRelayInit();
  tunnelPingInit();

  // Subscribe to packet callbacks
  crtpRegisterPortCB(CRTP_PORT_TUNNEL, crtpTunnelHandler);

  isInit = true;
}

bool tunnelCommTest() {
  bool pass = isInit;

  pass &= tunnelParametersTest();
  pass &= tunnelSignalTest();
  pass &= tunnelRelayTest();
  pass &= tunnelPingTest();

  return pass;
}