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

static Tunnel2DVel manual_vel;

void sendSetpointHover(float vx,float vy, float yawrate, float zDistance) {
  uint8_t type = 5; // hoverType, see crtp_commander_generic.c:71
  CRTPPacket pk;
  pk.port = CRTP_PORT_SETPOINT_GENERIC;
  pk.channel = 0;
  uint8_t *p = pk.data; memcpy(p, &type, sizeof(type));
  p += sizeof(type);    memcpy(p, &vx, sizeof(vx));
  p += sizeof(vx);      memcpy(p, &vy, sizeof(vy));
  p += sizeof(vy);      memcpy(p, &yawrate, sizeof(yawrate));
  p += sizeof(yawrate); memcpy(p, &zDistance, sizeof(zDistance));
  pk.size = sizeof(type) + sizeof(vx) + sizeof(vy) + sizeof(yawrate) + sizeof(zDistance);

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
  if(rangeGet(rangeUp) < 200) {
    ledSetAll();
    sendSetpointStop();
    vTaskDelay(5000);
    ledClearAll();
  }

  //TODO get desired movement from behavior
  Tunnel2DVel movement;
  tunnelBehaviorUpdate(&movement);

  //TODO get repulsion from avoider
  Tunnel2DVel repulsion;
  tunnelAvoiderUpdate(&repulsion);

  //TODO calculate final movement

  // Send the movement command
  if(getTunnelCanFly())
    sendSetpointHover(0.3f * (float)manual_vel.vx + repulsion.vx, 
                      0.3f * (float)manual_vel.vy + repulsion.vy, 0, 0.2f);
}

void crtpTunnelCommanderHandler(CRTPPacket *p) {
  /*
  DEBUG_PRINT("Tmsg s=%i c=", p->size);
  for(int i = 0; i < p->size; i++)
    DEBUG_PRINT("%i,", p->data[i]);
  DEBUG_PRINT("\n");

  manual_vel.vx = (int8_t)p->data[0];
  manual_vel.vy = (int8_t)p->data[1];

  DEBUG_PRINT("CMD = %i %i\n", manual_vel.vx, manual_vel.vy);

  CRTPPacket pk;
  pk.port = CRTP_PORT_TUNNEL;
  pk.channel = 1;
  memcpy(pk.data, p->data, p->size);
  pk.size = p->size;
  crtpSendPacket(&pk);
  */
}

void tunnelCommanderInit() {
  tunnelAvoiderInit();
  tunnelBehaviorInit();
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
