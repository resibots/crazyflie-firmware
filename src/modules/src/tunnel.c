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
#include "tunnel_behavior.h"

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

static bool isInit = false;

// Manage drone state transitions
static DroneState droneState;
DroneState tunnelGetDroneState() { return droneState; }
void tunnelSetDroneState(DroneState newState) {
  switch(newState) {
    case DRONE_STATE_INACTIVE:
    case DRONE_STATE_IDLE:
    case DRONE_STATE_CRASHED:
      sendSetpointStop();
      tunnelSetBehavior(TUNNEL_BEHAVIOR_IDLE);
      setTunnelCanFly(false);
      break;
    case DRONE_STATE_FLYING:
      setTunnelCanFly(true);
      tunnelSetBehavior(TUNNEL_BEHAVIOR_TAKE_OFF);
      break;
  }
  droneState = newState;
}

// Manage drone role transitions
static DroneRole droneRole;
DroneRole tunnelGetDroneRole() { return droneRole; }
void tunnelSetDroneRole(DroneRole newRole) { droneRole = newRole; }

typedef enum {
  CRTP_TUNNEL_CHANNEL_PING      = 0x00,
  CRTP_TUNNEL_CHANNEL_PARAM     = 0x01,
  CRTP_TUNNEL_CHANNEL_COMMANDER = 0x02,
  CRTP_TUNNEL_CHANNEL_COMMAND   = 0x03,
} CRTPTunnelChannel;

typedef enum {
  CRTP_TUNNEL_COMMAND_TAKE_OFF = 0x00, // Start flying and do our thing!
  CRTP_TUNNEL_COMMAND_LAND     = 0x01, // Land no matter where we are (e.g. to manually save battery)
  CRTP_TUNNEL_COMMAND_RTH      = 0x02, // Return to home automatically
  CRTP_TUNNEL_COMMAND_STOP     = 0x03, // Stop the motors and return to Idle state (for emergencies or tests)
} CRTPTunnelCommand;

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
      vTaskDelayUntil(&lastWakeTime, M2T(1000 / TUNNEL_TASK_RATE_HZ));

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
  else if(p->channel == CRTP_TUNNEL_CHANNEL_COMMAND) {
    switch(p->data[0]) {
      case CRTP_TUNNEL_COMMAND_TAKE_OFF:
        tunnelSetDroneState(DRONE_STATE_FLYING);
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

void tunnelInit() {
  if(isInit)
    return;

  // State definitions
  tunnelSetDroneState(DRONE_STATE_IDLE);
  tunnelSetDroneRole((getDroneId() == 0) ? DRONE_ROLE_HEAD : DRONE_ROLE_FOLLOWER);

  // Set follower and leader
  if(getDroneId() > 0)
    setLeaderID(getDroneId() - 1);
  if(getDroneId() < getNDrones() - 1)
    setFollowerID(getDroneId() + 1);
  
  // Don't fly if we're not in the active chain
  // TODO refresh this when changing NDrones
  if(getDroneId() >= getNDrones())
    tunnelSetDroneState(DRONE_STATE_INACTIVE);

  // Init submodules
  tunnelPingInit();
  tunnelParametersInit();
  tunnelCommanderInit();

  // Subscribe to packet callbacks
  crtpRegisterPortCB(CRTP_PORT_TUNNEL, crtpTunnelHandler);

  // Create the main tunnel task
  xTaskCreate(tunnelTask, TUNNELEXPLORER_TASK_NAME, TUNNELEXPLORER_TASK_STACKSIZE, NULL,
              TUNNELEXPLORER_TASK_PRI, NULL);
  
  isInit = true;
}

bool tunnelTest() {
  bool pass = isInit;

  pass &= tunnelPingTest();
  pass &= tunnelParametersTest();
  pass &= tunnelCommanderTest();

  return pass;
}

