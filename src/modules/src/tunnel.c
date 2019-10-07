/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel.c - Tunnel exploration module's entry point. 
 *            Calls each submodule and manages the main drone states.
 */

#include "tunnel.h"

#include "tunnel_config.h"
#include "tunnel_ping.h"
#include "tunnel_commander.h"
#include "tunnel_parameters.h"

#define DEBUG_MODULE "TUN"
#include "debug.h"

#include "FreeRTOS.h"
#include "task.h"

#include "system.h"
#include "led.h"
#include "ledseq.h"

#include "crtp.h"
#include "p2p.h"
#include "radiolink.h"

typedef enum {
  CRTP_TUNNEL_CHANNEL_PING      = 0x00,
  CRTP_TUNNEL_CHANNEL_PARAM     = 0x01,
  CRTP_TUNNEL_CHANNEL_COMMANDER = 0x02,
} CRTPTunnelChannel;

static void tunnelTask(void *param) {
    systemWaitStart();
    vTaskDelay(2000);

    // Set the max radio TX Power
    radiolinkSetPowerDbm(4);

    // Stop red LED (it gets annoying ^^)
    ledseqStop(SYS_LED, seq_alive);
    ledseqStop(SYS_LED, seq_calibrated);
    ledSet(SYS_LED, false);

    TickType_t lastWakeTime = xTaskGetTickCount();

    while (1) {
      vTaskDelayUntil(&lastWakeTime, M2T(50));

      // Calculate the new drone movement and send it to the stabilizer
      tunnelCommanderUpdate();

      // Handle ping routines
      tunnelPingUpdate();
    }
}

void crtpTunnelHandler(CRTPPacket *p) {
  if(p->channel == CRTP_TUNNEL_CHANNEL_PING)
    crtpTunnelPingHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_PARAM)
    crtpTunnelParametersHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_COMMANDER)
    crtpTunnelCommanderHandler(p);
}

void tunnelInit() {
  // Init submodules
  tunnelPingInit();
  tunnelParametersInit();
  tunnelCommanderInit();

  // Subscribe to packet callbacks
  crtpRegisterPortCB(CRTP_PORT_TUNNEL, crtpTunnelHandler);

  // Create the main tunnel task
  xTaskCreate(tunnelTask, TUNNELEXPLORER_TASK_NAME, TUNNELEXPLORER_TASK_STACKSIZE, NULL,
              TUNNELEXPLORER_TASK_PRI, NULL);
}

bool tunnelTest() {
  bool pass = true;

  pass &= tunnelPingTest();
  pass &= tunnelParametersTest();
  pass &= tunnelCommanderTest();

  return pass;
}

