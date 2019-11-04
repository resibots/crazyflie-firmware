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

static bool isInit = false;
static unsigned long statusPrevTime = 0;

typedef enum {
  CRTP_TUNNEL_CHANNEL_PING      = 0x00,
  CRTP_TUNNEL_CHANNEL_PARAM     = 0x01,
  CRTP_TUNNEL_CHANNEL_COMMANDER = 0x02,
  CRTP_TUNNEL_CHANNEL_COMMAND   = 0x03,
} CRTPTunnelChannel;

typedef enum {
  CRTP_TUNNEL_COMMAND_TAKE_OFF   = 0x00, // Start flying and do our thing!
  CRTP_TUNNEL_COMMAND_MOVE_DRONE = 0x01, // Ask to move a drone (will be transmitted if necessary)
  CRTP_TUNNEL_COMMAND_SCAN       = 0x02, // Scan the room and send the measurements
  CRTP_TUNNEL_COMMAND_LAND       = 0x03, // Land no matter where we are (e.g. to manually save battery)
  CRTP_TUNNEL_COMMAND_RTH        = 0x04, // Return to home automatically
  CRTP_TUNNEL_COMMAND_STOP       = 0x05, // Stop the motors and return to Idle state (for emergencies or tests)

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
  if(batteryVt > 0x0F) batteryVt = 0x00; // Report a calculation error as a fully empty battery

  // Send battery level, Drone role, Drone state, Current behavior
  pkData[0] = ((batteryVt             << 4) & 0xF0) | (tunnelGetDroneRole()       & 0x0F);
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
  DEBUG_PRINT("STATUS %02x%02x\n", p_status.txdata[0], p_status.txdata[1]);

  p2pSendPacket(&p_status);
}

void tunnelCommUpdate() {
  // Handle ping routines
  tunnelPingUpdate();

  // Broadcast our own status regularly (don't pollute the air traffic with inactive drones)
  if(tunnelGetDroneState() != DRONE_STATE_INACTIVE && timerElapsed(&statusPrevTime, 200))
    broadcastStatus();
}

void crtpTunnelHandler(CRTPPacket *p) {
  if(p->channel == CRTP_TUNNEL_CHANNEL_PING)
    crtpTunnelPingHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_PARAM)
    crtpTunnelParametersHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_COMMANDER)
    crtpTunnelCommanderHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_COMMAND) {
    switch(p->data[0]) {
      case CRTP_TUNNEL_COMMAND_TAKE_OFF:
        tunnelSetDroneState(DRONE_STATE_FLYING);
        break;
      case CRTP_TUNNEL_COMMAND_MOVE_DRONE:
        DEBUG_PRINT("Moving drone %i\n", p->data[1]);
        if(p->data[1] == getDroneId())
          tunnelCommanderProcessPacket(&p->data[2]);
        else {
          P2PPacket p_move;
          p_move.port = P2P_PORT_COMMANDER;
          p_move.txdest = p->data[1];
          memcpy(p_move.txdata, &p->data[2], p->size - 2);
          p_move.size = p->size - 2;
          tunnelSendP2PPacket(&p_move);
        }
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