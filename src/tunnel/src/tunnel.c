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
#include "tunnel_commander.h"
#include "tunnel_behavior.h"
#include "tunnel_comm.h"
#include "tunnel_relay.h"

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

static void tunnelTask(void *param) {
  systemWaitStart();
  vTaskDelay(2000);

  // Set the max radio TX Power
  radiolinkSetPowerDbm(4);

  // Stop red LED (it gets annoying ^^)
  ledseqStop(SYS_LED, seq_alive);
  ledseqStop(SYS_LED, seq_calibrated);
  ledSet(SYS_LED, false);

  // Print some information
  DEBUG_PRINT("Drone ID: %i\n", getDroneId());

  TickType_t lastWakeTime = xTaskGetTickCount();

  while (1) {
    vTaskDelayUntil(&lastWakeTime, M2T(1000 / TUNNEL_TASK_RATE_HZ));

    // Calculate the new drone movement and send it to the stabilizer
    tunnelCommanderUpdate();

    // Handle communication routines
    tunnelCommUpdate();
  }
}

void tunnelInit() {
  if(isInit) return;

  // State definitions
  tunnelSetDroneRole((getDroneId() == 0) ? DRONE_ROLE_HEAD : DRONE_ROLE_RELAY);

  // Set follower and leader
  tunnelAutoSetFollowerLeader();
  tunnelAutoSetIdleInactive();

  // Init submodules  
  tunnelCommanderInit();
  tunnelCommInit();

  // Create the main tunnel task
  xTaskCreate(tunnelTask, TUNNELEXPLORER_TASK_NAME, TUNNELEXPLORER_TASK_STACKSIZE, NULL,
              TUNNELEXPLORER_TASK_PRI, NULL);
  
  isInit = true;
}

bool tunnelTest() {
  bool pass = isInit;

  pass &= tunnelCommanderTest();
  pass &= tunnelCommTest();

  return pass;
}

