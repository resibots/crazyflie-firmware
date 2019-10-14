/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_commander.c - calculates and sends the drone's movement based on:
 *  - Obstacles with the multiranger deck
 *  - RSSI values between the nearby drones
 * 
 * Is part of the navigation stack (commander, avoider & behavior).
 */

#include "tunnel_commander.h"
#include "tunnel_config.h"
#include "tunnel_avoider.h"
#include "tunnel_behavior.h"

#define DEBUG_MODULE "TUN_CMD"
#include "debug.h"

#include "FreeRTOS.h"
#include "task.h"
#include "config.h"

#include "system.h"
#include "configblock.h"
#include "range.h"
#include "led.h"
#include "ledseq.h"
#include "log.h"

#include "crtp.h"
#include "p2p.h"
#include "commander.h"
#include "crtp_commander.h"

typedef enum {
  TUNNEL_COMMANDER_MOVE = 0x00
} TunnelCommanderRequest;

static TunnelHover manual_vel;

void sendSetpointHover(TunnelHover *hover) {
  uint8_t type = 5; // hoverType, see crtp_commander_generic.c:71
  CRTPPacket pk;
  pk.port = CRTP_PORT_SETPOINT_GENERIC;
  pk.channel = 0;
  uint8_t *p = pk.data; memcpy(p, &type, sizeof(type));
  p += sizeof(type);    memcpy(p, &hover->vx, sizeof(hover->vx));
  p += sizeof(hover->vx);      memcpy(p, &hover->vy, sizeof(hover->vy));
  p += sizeof(hover->vy);      memcpy(p, &hover->yawrate, sizeof(hover->yawrate));
  p += sizeof(hover->yawrate); memcpy(p, &hover->zDistance, sizeof(hover->zDistance));
  pk.size = sizeof(type) + sizeof(hover->vx) + sizeof(hover->vy) + sizeof(hover->yawrate) + sizeof(hover->zDistance);

  setpoint_t setpoint;
  crtpCommanderGenericDecodeSetpoint(&setpoint, &pk);
  commanderSetSetpoint(&setpoint, COMMANDER_PRIORITY_CRTP);
}

void sendSetpointStop() {
  uint8_t type = 0; // stopType, see crtp_commander_generic.c:66
  CRTPPacket pk;
  pk.port = CRTP_PORT_SETPOINT_GENERIC;
  pk.channel = 0;
  memcpy(pk.data, &type, sizeof(type));
  pk.size = 1;

  setpoint_t setpoint;
  crtpCommanderGenericDecodeSetpoint(&setpoint, &pk);
  commanderSetSetpoint(&setpoint, COMMANDER_PRIORITY_CRTP);
}

void tunnelCommanderUpdate() {
  // Red switch for tests
#ifdef TUNNEL_RED_SWITCH
  if(rangeGet(rangeUp) < 50) {
    sendSetpointStop();
    setTunnelCanFly(false);
  }
#endif

  // Get desired movement from behavior
  bool enableAvoider = true;
  TunnelHover movement;
  tunnelBehaviorUpdate(&movement, &enableAvoider);

  // Get repulsion from avoider
  if(enableAvoider) tunnelAvoiderUpdate(&movement);

  // Calculate final movement
  movement.vx      += manual_vel.vx     ;
  movement.vy      += manual_vel.vy     ;
  movement.yawrate += manual_vel.yawrate;

  // Send the movement command (only when this module is allowed to send setpoints)
  if(getTunnelCanFly()) {
    if(movement.zDistance > 0)
      sendSetpointHover(&movement);
    else sendSetpointStop();
  }
}

static void processTunnelCommanderPacket(uint8_t* data) {
  switch(data[0]) {
    // Directly move the drone: rxdata = [TUNNEL_COMMANDER_MOVE][int8_t vx][int8_t vy]
    case TUNNEL_COMMANDER_MOVE:
      manual_vel.vx = 0.3f * (float)(int8_t)data[1];
      manual_vel.vy = 0.3f * (float)(int8_t)data[2];
      break;
  }
}

void crtpTunnelCommanderHandler(CRTPPacket *p) {
  processTunnelCommanderPacket(p->data);
}

void p2pTunnelCommanderHandler(P2PPacket *p) {
  processTunnelCommanderPacket(p->rxdata);
}

void tunnelCommanderInit() {
  // Register commander callbacks. CRTP callback is called from tunnel.c
  p2pRegisterPortCB(P2P_PORT_COMMANDER, p2pTunnelCommanderHandler);

  // Initialize submodules
  tunnelAvoiderInit();
  tunnelBehaviorInit();

  // Initialize structures
  manual_vel.vx        = 0;
  manual_vel.vy        = 0;
  manual_vel.yawrate   = 0;
  manual_vel.zDistance = 0;
}

bool tunnelCommanderTest() {
  bool pass = true;

  pass &= tunnelAvoiderTest();
  pass &= tunnelBehaviorTest();

  return pass;
}

/* TODO old code just in case, remove
RSSI amd connection LED feedback
bool isConnected = logGetUint(logGetVarId("radio", "isConnected"));
int rssi = (int)logGetFloat(logGetVarId("radio", "rssi"));
uint8_t rssi_scaled = LIMIT(LINSCALE(35, 85, 0, 255, rssi));
DEBUG_PRINT("connected=%i rssi=%i\n", isConnected, rssi);
ledSet(LED_GREEN_R, isConnected);
*/
