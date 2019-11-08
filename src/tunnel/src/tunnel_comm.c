/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_comm.c - Handles the drone's communication routines
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

#define DEBUG_MODULE "TCM"
#include "debug.h"
#include "led.h"
#include "ledseq.h"
#include "crtp.h"

static bool isInit = false;
static unsigned long statusPrevTime = 0;

typedef enum {
  CRTP_TUNNEL_CHANNEL_PING      = 0x00,
  CRTP_TUNNEL_CHANNEL_PARAM     = 0x01,
  CRTP_TUNNEL_CHANNEL_COMMANDER = 0x02,
  CRTP_TUNNEL_CHANNEL_COMMAND   = 0x03,
} CRTPTunnelChannel;

typedef enum {
  CRTP_TUNNEL_COMMAND_TAKE_OFF       = 0x00, // Start flying and do our thing!
  CRTP_TUNNEL_COMMAND_SCAN           = 0x01, // Scan the room and send the measurements
  CRTP_TUNNEL_COMMAND_LAND           = 0x02, // Land no matter where we are (e.g. to manually save battery)
  CRTP_TUNNEL_COMMAND_RTH            = 0x03, // Return to home automatically
  CRTP_TUNNEL_COMMAND_STOP           = 0x04, // Stop the motors and return to Idle state (for emergencies or tests)

  //TODO implement
  CRTP_TUNNEL_COMMAND_CHAIN_START    = 0x06, // Start flying (head takes off, second drone armed, others idle or inactive)
  CRTP_TUNNEL_COMMAND_CHAIN_RTH      = 0x07, // Return to home (no more head, all automatic)
  CRTP_TUNNEL_COMMAND_CHAIN_SHUTDOWN = 0x08, // Emergency only: all drones cut motors off immediately
  CRTP_TUNNEL_COMMAND_CHAIN_PING     = 0x09, // Ping the chain and return the status of each drone
} CRTPTunnelCommand;

// Returns the size used and fills general information about the drone
uint8_t appendStatusMessage(uint8_t *pkData) {
  // Calculate battery level
  uint8_t batteryVt = BATTERY_RES * (pmGetBatteryVoltage() - BATTERY_MIN) / (BATTERY_MAX - BATTERY_MIN);
  if(!pmIsDischarging() || batteryVt > 0x0F) batteryVt = 0x0F;

  // Join drone role and connections to leader/follower/base in one byte
  uint8_t statusBits = ((tunnelGetDroneRole() == DRONE_ROLE_HEAD ? 1 : 0) << 3) | // Set if the drone is the chain's head
                       (tunnelIsDroneConnected(getLeaderID())             << 2) | // Set if there's a good connection with the leader
                       (tunnelIsDroneConnected(getFollowerID())           << 1) | // Set if there's a good connection with the follower
                       tunnelIsBaseConnected();           // Set if the drone is connected to the base via CRTP

  // Send battery level, Drone role, Drone state, Current behavior
  pkData[0] = ((batteryVt             << 4) & 0xF0) | (statusBits                 & 0x0F);
  pkData[1] = ((tunnelGetDroneState() << 4) & 0xF0) | (tunnelGetCurrentBehavior() & 0x0F);
  return 2;
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
  if(tunnelGetDroneState() != DRONE_STATE_INACTIVE && timerElapsed(&statusPrevTime, 200))
    broadcastStatus();

  if(getDroneId() == 1) { //TODO remove
    P2PPacket p_trace;
    p_trace.port = 7;
    p_trace.txdata[0] = 0xAB;
    p_trace.size = 1;
    tunnelTraceP2PPacket(&p_trace, TRACE_MODE_BACKWARD);
  }
}

void processIncomingCRTPPacket(CRTPTunnelPacket* p) {
  if(p->channel == CRTP_TUNNEL_CHANNEL_PING)
    crtpTunnelPingHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_PARAM)
    crtpTunnelParametersHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_COMMANDER)
    crtpTunnelCommanderHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_COMMAND) {
    switch(p->dronedata[0]) {
      case CRTP_TUNNEL_COMMAND_TAKE_OFF:
        tunnelSetDroneState(DRONE_STATE_FLYING);
        break;
      case CRTP_TUNNEL_COMMAND_SCAN:
        tunnelSetBehavior(TUNNEL_BEHAVIOR_SCAN);
        break;
      case CRTP_TUNNEL_COMMAND_LAND:
        tunnelSetBehavior(TUNNEL_BEHAVIOR_LAND);
        break;
      case CRTP_TUNNEL_COMMAND_RTH:
        //TODO
        break;
      case CRTP_TUNNEL_COMMAND_STOP:
        tunnelSetDroneState(DRONE_STATE_IDLE);
        break;
    }
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

void callback(P2PPacket* p) { //TODO remove
  if(p->rxdest == getDroneId()) {
    // DEBUG_PRINT("Got trace\n");
    // p2pPrintPacket(p, true);
    ledseqRun(LED_GREEN_R, seq_testPassed);
  }
}

void tunnelCommInit() {
  if(isInit) return;

  tunnelParametersInit();
  tunnelSignalInit();
  tunnelRelayInit();
  tunnelPingInit();

  // Subscribe to packet callbacks
  crtpRegisterPortCB(CRTP_PORT_TUNNEL, crtpTunnelHandler);
  p2pRegisterPortCB(7, callback); //TODO remove

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