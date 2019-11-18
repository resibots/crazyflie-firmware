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
      if(tunnelGetCurrentBehavior() == TUNNEL_BEHAVIOR_IDLE) {
        // Set LED state
        ledseqStop(LED_GREEN_R, seq_armed);
        ledSet(LED_GREEN_R, false);
      }
      else { // If we are flying, land before cutting motors
        tunnelSetBehavior(TUNNEL_BEHAVIOR_LAND);
        droneState = DRONE_STATE_FLYING;
        return;
      }
      break;
    case DRONE_STATE_ARMED:
      // Set LED state
      ledseqRun(LED_GREEN_R, seq_armed);
      ledSet(LED_GREEN_R, false);
      break;
    case DRONE_STATE_FLYING:
      if(tunnelGetCurrentBehavior() != TUNNEL_BEHAVIOR_IDLE)
        tunnelSetBehavior(TUNNEL_BEHAVIOR_TAKE_OFF);

      // Set LED state
      ledseqStop(LED_GREEN_R, seq_armed);
      ledSet(LED_GREEN_R, true);
      break;
    case DRONE_STATE_CRASHED:
      // Cut motors immediately
      tunnelSetBehavior(TUNNEL_BEHAVIOR_IDLE);

      // Set LED state
      ledseqStop(LED_GREEN_R, seq_armed);
      ledSet(LED_GREEN_R, false);
      break;
  }
  droneState = newState;
}

// Manage drone mode transitions
static DroneMode droneMode;
DroneMode tunnelGetDroneMode() { return droneMode; }
void tunnelSetDroneMode(DroneMode newMode) {
  if(tunnelGetDroneMode() != newMode) {
    droneMode = newMode;

    if(newMode == DRONE_MODE_MANUAL && tunnelGetDroneState() == DRONE_STATE_FLYING)
      tunnelSetDroneState(DRONE_STATE_IDLE);
  }
}

// Manage drone role transitions
static DroneRole droneRole;
DroneRole tunnelGetDroneRole() { return droneRole; }
void tunnelSetDroneRole(DroneRole newRole) { droneRole = newRole; }

static void handleAutoStates() {
  switch(tunnelGetDroneState()) {
    case DRONE_STATE_IDLE: {
      // Launch the head drone automatically
      if(getDroneId() == 0) {
        DEBUG_PRINT("Launch head!\n");
        tunnelSetDroneState(DRONE_STATE_FLYING);
      }

      // Arm the drone if the leader is flying (meaning it might need us to relay it if it goes too far away)
      if(tunnelIsDroneConnected(getLeaderID()) && tunnelGetLeaderStatus()->droneState == DRONE_STATE_FLYING) {
        DEBUG_PRINT("Leader flying, auto arm!\n");
        tunnelSetDroneState(DRONE_STATE_ARMED);
      }
      break;
    }
    case DRONE_STATE_ARMED: {
      // Launch the drone if the leader got too far away
      if((isPeerIDValid(getLeaderID()) && !tunnelIsDroneConnected(getLeaderID())) || 
        (tunnelIsDroneConnected(getLeaderID()) && tunnelGetLeaderSignal()->rssi > TUNNEL_RSSI_ARMED + TUNNEL_RSSI_GROUND_PENALTY)) {
        DEBUG_PRINT("Leader far, auto take off!\n");
        tunnelSetDroneState(DRONE_STATE_FLYING);
      }

      // Go back to idle if the leader landed
      if(tunnelIsDroneConnected(getLeaderID()) && tunnelGetLeaderStatus()->droneState < DRONE_STATE_FLYING) {
        DEBUG_PRINT("Disarming, leader landed.\n");
        tunnelSetDroneState(DRONE_STATE_IDLE);
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
  DEBUG_PRINT("Drone Role: %i\n", tunnelGetDroneRole());

  TickType_t lastWakeTime = xTaskGetTickCount();

  // Main tunnel loop
  while (1) {
    vTaskDelayUntil(&lastWakeTime, M2T(1000 / TUNNEL_TASK_RATE_HZ));

    // Manage state changes based on new information sent by other drones
    if(tunnelGetDroneMode() == DRONE_MODE_AUTO)
      handleAutoStates();

    // Calculate the new drone movement and send it to the stabilizer
    tunnelCommanderUpdate();

    // Handle communication routines
    tunnelCommUpdate();
  }
}

void tunnelInit() {
  if(isInit) return;

  // State definitions
  if(getDroneId() == 0)
    tunnelSetDroneRole(DRONE_ROLE_HEAD);
  else if(getDroneId() >= getNDrones() - 1)
    tunnelSetDroneRole(DRONE_ROLE_BASE);
  else
    tunnelSetDroneRole(DRONE_ROLE_RELAY);

  tunnelAutoSetIdleInactive();
  tunnelSetDroneMode(DRONE_MODE_MANUAL);

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

