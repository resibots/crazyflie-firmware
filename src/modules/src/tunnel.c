#include "tunnel.h"

#include "tunnel_config.h"
#include "tunnel_ping.h"
#include "tunnel_commander.h"

#define DEBUG_MODULE "TUN"
#include "debug.h"

#include "FreeRTOS.h"
#include "task.h"

#include "system.h"
#include "led.h"
#include "ledseq.h"

#include "crtp.h"
#include "p2p.h"

typedef enum {
  CRTP_TUNNEL_CHANNEL_PING      = 0x00,
  CRTP_TUNNEL_CHANNEL_COMMANDER = 0x01,
} CRTPTunnelChannel;

static void tunnelTask(void *param) {
    systemWaitStart();
    vTaskDelay(2000);

    // Stop red LED (it gets annoying ^^)
    ledseqStop(SYS_LED, seq_alive);
    ledseqStop(SYS_LED, seq_calibrated);
    ledSet(SYS_LED, false);

    TickType_t lastWakeTime = xTaskGetTickCount();

    while (1) {
      vTaskDelayUntil(&lastWakeTime, M2T(100));

      // Update commander
      tunnelCommanderUpdate();

      // Handle ping routines
      tunnelPingUpdate();
    }
}

void crtpTunnelHandler(CRTPPacket *p) {
  if(p->channel == CRTP_TUNNEL_CHANNEL_PING)
    crtpTunnelPingHandler(p);
  else if(p->channel == CRTP_TUNNEL_CHANNEL_COMMANDER)
    crtpTunnelCommanderHandler(p);
}

void p2pParamHandler(P2PPacket *p) {
  setNDrones(p->rxdata[0]); // set nDrones for now only TODO
}

void tunnelInit() {
  // Init submodules
  tunnelCommanderInit();
  tunnelPingInit();

  // Subscribe to packet callbacks
  crtpRegisterPortCB(CRTP_PORT_TUNNEL, crtpTunnelHandler);
  p2pRegisterPortCB(P2P_PORT_PARAM,    p2pParamHandler);

  // Create the main tunnel task
  xTaskCreate(tunnelTask, TUNNELEXPLORER_TASK_NAME, TUNNELEXPLORER_TASK_STACKSIZE, NULL, 
              TUNNELEXPLORER_TASK_PRI, NULL);
}

bool tunnelTest() {
  bool pass = true;

  pass &= tunnelPingTest();
  pass &= tunnelCommanderTest();

  return pass;
}

