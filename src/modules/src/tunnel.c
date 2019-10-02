#include "tunnel.h"

#define DEBUG_MODULE "TUN"
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

// Number of available drones in the tunnel exploration crew
static uint8_t nDrones = 3; // 15 max because of the 4-bit addresses

#define ABS(x) (x > 0) ? x : -x
#define LINSCALE(domain_low, domain_high, codomain_low, codomain_high, value) (((codomain_high - codomain_low) / (domain_high - domain_low)) * (value - domain_low) + codomain_low)

static P2PPacket reply;
static unsigned long nextSend = 0;

uint8_t getDroneId() {
  return (uint8_t)configblockGetRadioAddress() & 0x0F;
}

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

static void mrTask(void *param)
{
    systemWaitStart();
    vTaskDelay(2000);

    // Stop red LED (it gets annoying ^^)
    ledseqStop(SYS_LED, seq_alive);
    ledseqStop(SYS_LED, seq_calibrated);
    ledSet(SYS_LED, false);

    TickType_t lastWakeTime = xTaskGetTickCount();

    uint8_t counter = 0;

    while (1)
    {
      vTaskDelayUntil(&lastWakeTime, M2T(100));

      if(nextSend != 0 && xTaskGetTickCount() > nextSend) {
        p2pSendPacket(&reply);
        ledSet(LED_GREEN_R, false);
        nextSend = 0;
      }

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
}

void crtpTunnelHandler(CRTPPacket *p) {
  DEBUG_PRINT("Sending ping...\n");
  P2PPacket p2p_p;

  if(getDroneId() == 0)
    p2p_p.txdest = 1;
  else if(getDroneId() == nDrones - 1)
    p2p_p.txdest = nDrones - 2;
  else
    reply.txdest = getDroneId() + 1;

  p2p_p.port   = P2P_PORT_PING;
  p2p_p.txdata[0] = p->data[0]; // propagate or not
  p2p_p.txdata[1] = 0x66; // data to repeat
  p2p_p.size = 2;         // Consider data size only (no header)
  p2pSendPacket(&p2p_p);

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

void p2pPingHandler(P2PPacket *p) {
  DEBUG_PRINT("Got ping:\n");
  p2pPrintPacket(p, true);

  // The first drone doesn't reply to propagating pings
  if(p->rxdest == getDroneId() && getDroneId() == 0 && p->rxdata[0] == 0x01) {
    ledseqRun(LED_GREEN_R, seq_testPassed);
    return;
  }

  if(p->rxdest == getDroneId()) {
    // first byte tells if the ping has to propagate through the chain
    if(p->size >= 1 && p->rxdata[0] == 0x01) { 
      reply.txdest = getDroneId();
      if(getDroneId() == 0) // first drone replies to second
        reply.txdest = 1;
      else if(getDroneId() == nDrones - 1) // last drone replies to n-1
        reply.txdest = nDrones - 2;
      else // middle drone propagates the ping
        reply.txdest += (p->rxdest - p->origin > 0) ? 1 : -1;
    }
    else // reply back directly
      reply.txdest = p->origin;
    
    memcpy(reply.txdata, p->rxdata, p->size);
    reply.size = p->size;

    nextSend = xTaskGetTickCount() + 500; // send reply after some time
    ledSet(LED_GREEN_R, true);
  }
}

void p2pTunnelHandler(P2PPacket *p) {
  
}

void tunnelInit()
{
  crtpRegisterPortCB(CRTP_PORT_TUNNEL, crtpTunnelHandler);
  p2pRegisterPortCB(P2P_PORT_TUNNEL, p2pTunnelHandler);
  p2pRegisterPortCB(P2P_PORT_PING, p2pPingHandler);

  xTaskCreate(mrTask, TUNNELEXPLORER_TASK_NAME, TUNNELEXPLORER_TASK_STACKSIZE, NULL, 
              TUNNELEXPLORER_TASK_PRI, NULL);
}

bool tunnelTest()
{
  return true;
}

