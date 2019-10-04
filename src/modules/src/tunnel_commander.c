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
 */

#include "tunnel_commander.h"
#include "tunnel_config.h"

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

#define ABS(x) (x > 0) ? x : -x
#define LINSCALE(domain_low, domain_high, codomain_low, codomain_high, value) (((codomain_high - codomain_low) / (domain_high - domain_low)) * (value - domain_low) + codomain_low)

struct {
  int8_t x;
  int8_t y;
} cmd_vel;

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

void tunnelCommanderUpdate()
{
    // // Red button : put a hand above it to stop for 5 seconds
    // if(rangeGet(rangeUp) < 300) {
    //   sendSetpointStop();
    //   vTaskDelay(5000);
    // }

    // // RSSI amd connection LED feedback
    // // bool isConnected = logGetUint(logGetVarId("radio", "isConnected"));
    // // int rssi = (int)logGetFloat(logGetVarId("radio", "rssi"));
    // // uint8_t rssi_scaled = LIMIT(LINSCALE(35, 85, 0, 255, rssi));
    // // DEBUG_PRINT("connected=%i rssi=%i\n", isConnected, rssi);
    // // ledSet(LED_GREEN_R, isConnected);

    // float left  = rangeGet(rangeLeft);
    // float right = rangeGet(rangeRight);

    // // LEDs for some visual obstacle detection feedback
    // if(left < 300) ledSet(LED_GREEN_R, true);
    // else ledSet(LED_GREEN_R, false);
    // if(right < 300) ledSet(LED_RED_R, true);
    // else ledSet(LED_RED_R, false);
    
    // // If there are two walls on each side, center the drone
    // float repulsion = 0;
    // if(left < 2000 && right < 2000) {
    //   float diff = left - right;
    //   if(diff < 0) diff *= -1;
    //   float sign = (left - right > 0) ? 1.f : -1.f;
    
    //   if(diff > 500) 
    //     repulsion = sign * 0.5f;
    //   else 
    //     repulsion = sign * LINSCALE(0.f, 500.f, 0.1f, 0.5f, diff);
    // }

    // // Send the movement command
    // //sendSetpointHover(0.3f * (float)cmd_vel.x, 0.3f * (float)cmd_vel.y + repulsion, 0, 0.3f);
}

void crtpTunnelCommanderHandler(CRTPPacket *p) {
//   DEBUG_PRINT("Tmsg s=%i c=", p->size);
//   for(int i = 0; i < p->size; i++)
//     DEBUG_PRINT("%i,", p->data[i]);
//   DEBUG_PRINT("\n");

//   cmd_vel.x = (int8_t)p->data[0];
//   cmd_vel.y = (int8_t)p->data[1];

//   DEBUG_PRINT("CMD = %i %i\n", cmd_vel.x, cmd_vel.y);

//   CRTPPacket pk;
//   pk.port = CRTP_PORT_TUNNEL;
//   pk.channel = 1;
//   memcpy(pk.data, p->data, p->size);
//   pk.size = p->size;
//   crtpSendPacket(&pk);
}

void tunnelCommanderInit() {
  
}

bool tunnelCommanderTest() {
  return true;
}
