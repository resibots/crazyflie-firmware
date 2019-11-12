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
#include "tunnel_signal.h"

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

      // Set LED state
      ledseqStop(LED_GREEN_R, seq_armed);
      ledSet(LED_GREEN_R, false);
      break;
    case DRONE_STATE_ARMED:
      // Set LED state
      ledseqRun(LED_GREEN_R, seq_armed);
      ledSet(LED_GREEN_R, false);
      break;
    case DRONE_STATE_FLYING:
      setTunnelCanFly(true);
      tunnelSetBehavior(TUNNEL_BEHAVIOR_TAKE_OFF);

      // Set LED state
      ledseqStop(LED_GREEN_R, seq_armed);
      ledSet(LED_GREEN_R, true);
      break;
  }
  droneState = newState;
}

// Manage drone role transitions
static DroneRole droneRole;
DroneRole tunnelGetDroneRole() { return droneRole; }
void tunnelSetDroneRole(DroneRole newRole) { droneRole = newRole; }

// Main tunnel task
static void tunnelTask(void *param) {
  systemWaitStart();
  vTaskDelay(2000);

  // Set the max radio TX Power
  radiolinkSetPowerDbm(4);

  // Stop red LED (it gets annoying ^^)
  ledseqStop(SYS_LED, seq_alive);
  ledseqStop(SYS_LED, seq_calibrated);
  ledSet(SYS_LED, false);

  // Print general startup information
  DEBUG_PRINT("Drone ID: %i\n", getDroneId());

  TickType_t lastWakeTime = xTaskGetTickCount();

  // Main tunnel loop
  while (1) {
    vTaskDelayUntil(&lastWakeTime, M2T(1000 / TUNNEL_TASK_RATE_HZ));

    // Calculate the new drone movement and send it to the stabilizer
    tunnelCommanderUpdate();

    // Handle communication routines
    tunnelCommUpdate();

    // Manage state changes based on new information sent by other drones
    switch(tunnelGetDroneState()) { //TODO finish states
      case DRONE_STATE_IDLE: {
        // Arm the drone if the leader is flying (meaning it might need us to relay it if it goes too far away)
        if(tunnelIsDroneConnected(getLeaderID()) && tunnelGetLeaderStatus()->droneState == DRONE_STATE_FLYING) {
          tunnelSetDroneState(DRONE_STATE_ARMED);
          DEBUG_PRINT("Leader flying, auto arm!\n");
        }
        break;
      }
      case DRONE_STATE_ARMED: {
        // Launch the drone if the leader got too far away
        if((isPeerIDValid(getLeaderID()) && !tunnelIsDroneConnected(getLeaderID())) || 
           (tunnelIsDroneConnected(getLeaderID()) && tunnelGetLeaderSignal()->rssi > TUNNEL_RSSI_ARMED + TUNNEL_RSSI_GROUND_PENALTY)) {
          tunnelSetDroneState(DRONE_STATE_FLYING);
          DEBUG_PRINT("Leader far, auto take off!\n");
        }

        // Go back to idle if the leader landed
        if(tunnelIsDroneConnected(getLeaderID()) && tunnelGetLeaderStatus()->droneState < DRONE_STATE_FLYING) {
          tunnelSetDroneState(DRONE_STATE_IDLE);
          DEBUG_PRINT("Disarming, leader landed.\n");
        }
        break;
      }
      case DRONE_STATE_FLYING: {
        // Land the drone if the leader comes back
        if(getTunnelFlightTime() > 2000 && 
           (tunnelIsDroneConnected(getLeaderID()) && tunnelGetLeaderSignal()->rssi < TUNNEL_RSSI_ARMED)) { //TODO test, remove
          tunnelSetBehavior(TUNNEL_BEHAVIOR_LAND);
          DEBUG_PRINT("Leader came back, auto land!\n");
        }
        break;
      }
      case DRONE_STATE_CRASHED:
        break;
    }
  }
}

void tunnelInit() {
  if(isInit) return;

  // State definitions
  tunnelSetDroneRole((getDroneId() == 0) ? DRONE_ROLE_HEAD : DRONE_ROLE_RELAY);
  tunnelAutoSetIdleInactive();

  // Set follower and leader
  tunnelAutoSetFollowerLeader();

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

