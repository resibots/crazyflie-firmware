#define DEBUG_MODULE "tunnelExplorer"
#include "debug.h"

#include "deck.h"

#include "FreeRTOS.h"
#include "task.h"
#include "config.h"

#include "range.h"
#include "led.h"
#include "system.h"
#include "log.h"

#include "crtp.h"
#include "commander.h"
#include "crtp_commander.h"

#define LIMIT(a) ((a>255)?255:(a<0)?0:a)
#define ABS(x) (x > 0) ? x : -x
#define LINSCALE(domain_low, domain_high, codomain_low, codomain_high, value) (((codomain_high - codomain_low) / (domain_high - domain_low)) * (value - domain_low) + codomain_low)



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

  // for(int i = 0; i < pk.size; i++)
  //   DEBUG_PRINT("%i,", pk.data[i]);
  // DEBUG_PRINT("\n");

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

    vTaskDelay(1000);

    TickType_t lastWakeTime = xTaskGetTickCount();

    while (1)
    {
      // 10Hz rate
      vTaskDelayUntil(&lastWakeTime, M2T(100));

      // Red button : put a hand above it to stop for 5 seconds
      if(rangeGet(rangeUp) < 300) {
        sendSetpointStop();
        vTaskDelay(5000);
      }

      // RSSI amd connection LED feedback
      // bool isConnected = logGetUint(logGetVarId("radio", "isConnected"));
      // int rssi = (int)logGetFloat(logGetVarId("radio", "rssi"));
      // uint8_t rssi_scaled = LIMIT(LINSCALE(35, 85, 0, 255, rssi));
      // DEBUG_PRINT("connected=%i rssi=%i\n", isConnected, rssi);
      // ledSet(LED_GREEN_R, isConnected);

      float left  = rangeGet(rangeLeft);
      float right = rangeGet(rangeRight);

      // LEDs for some visual obstacle detection feedback
      if(left < 300) ledSet(LED_GREEN_R, true);
      else ledSet(LED_GREEN_R, false);
      if(right < 300) ledSet(LED_RED_R, true);
      else ledSet(LED_RED_R, false);
      
      // If there are two walls on each side, center the drone
      float repulsion = 0;
      if(left < 1000 && right < 1000) {
        float diff = left - right;
        if(diff < 0) diff *= -1;
        float sign = (left - right > 0) ? 1.f : -1.f;
      
        if(diff > 500) repulsion = 0.3f;
        else repulsion = sign * LINSCALE(0.f, 500.f, 0.1f, 0.3f, diff);
      }

      // Send the movement command
      sendSetpointHover(0, repulsion, 0, 0.3f);
    }
}

static void tunnelInit()
{
  xTaskCreate(mrTask, TUNNELEXPLORER_TASK_NAME, TUNNELEXPLORER_TASK_STACKSIZE, NULL, 
              TUNNELEXPLORER_TASK_PRI, NULL);
}

static bool tunnelTest()
{
  return true;
}

static const DeckDriver tunnelDriver = {
  .name = "tunnelExplorer",
  .init = tunnelInit,
  .test = tunnelTest,
};

DECK_DRIVER(tunnelDriver);