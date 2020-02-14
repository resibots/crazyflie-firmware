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

static void setDroneStateLED(DroneState state) {
  switch(tunnelGetDroneState()) {
    case DRONE_STATE_INACTIVE:
    case DRONE_STATE_IDLE:
      ledseqStop(LED_GREEN_R, seq_armed);
      ledSet(LED_GREEN_R, false);
      break;
    case DRONE_STATE_ARMED:
      ledSet(LED_GREEN_R, false);
      ledseqRun(LED_GREEN_R, seq_armed);
      break;
    case DRONE_STATE_FLYING:
      ledseqStop(LED_GREEN_R, seq_armed);
      ledSet(LED_GREEN_R, true);
      break;
    case DRONE_STATE_CRASHED:
      ledseqStop(LED_GREEN_R, seq_armed);
      ledSet(LED_GREEN_R, false);
      break;
  }
}

// Manage drone state transitions
static DroneState droneState;
DroneState tunnelGetDroneState() { return droneState; }
void tunnelSetDroneState(DroneState newState) {
  switch(newState) {
    case DRONE_STATE_INACTIVE:
    case DRONE_STATE_IDLE:
      if(tunnelGetCurrentBehavior() != TUNNEL_BEHAVIOR_IDLE) {
        tunnelSetBehavior(TUNNEL_BEHAVIOR_LAND);
        return;
      }
      break;
    case DRONE_STATE_FLYING:
      tunnelSetBehavior(TUNNEL_BEHAVIOR_TAKE_OFF);
      break;
    case DRONE_STATE_CRASHED:
      // Cut motors immediately
      tunnelSetBehavior(TUNNEL_BEHAVIOR_IDLE);
      break;
  }
  droneState = newState;
  setDroneStateLED(tunnelGetDroneState());
}

// Manage drone mode transitions
static DroneMode droneMode;
DroneMode tunnelGetDroneMode() { return droneMode; }
void tunnelSetDroneMode(DroneMode newMode) {
  ledSet(LED_BLUE_L, newMode == DRONE_MODE_AUTO);

  if(tunnelGetDroneMode() != newMode) {
    droneMode = newMode;

    if(newMode == DRONE_MODE_MANUAL)
      DEBUG_PRINT("Setting manual\n");
    else 
      DEBUG_PRINT("Setting auto\n");

    if(newMode == DRONE_MODE_MANUAL && tunnelGetDroneState() == DRONE_STATE_FLYING)
      tunnelSetDroneState(DRONE_STATE_IDLE);
  }
}

// Manage drone role transitions
static DroneRole droneRole;
DroneRole tunnelGetDroneRole() { return droneRole; }
void tunnelSetDroneRole(DroneRole newRole) { droneRole = newRole; }

static void handleAutoStates() {
  // Keep track of when the leader takes off. Used 
  static uint32_t leaderTakeoffTime = 0;
  if(getDroneId() != 0 && leaderTakeoffTime == 0 && tunnelIsDroneConnected(getLeaderID())) {
    if(tunnelGetLeaderStatus()->droneState == DRONE_STATE_FLYING)
      leaderTakeoffTime = xTaskGetTickCount();
    else leaderTakeoffTime = 0;
  }

  switch(tunnelGetDroneState()) {
    case DRONE_STATE_IDLE: {
      // Launch the head drone automatically
      if(getDroneId() == 0) {
        DEBUG_PRINT("Launch head!\n");
        tunnelSetDroneState(DRONE_STATE_FLYING);
      }

      // Arm the drone if the leader is flying (meaning it might need us to relay it if it goes too far away)
      if(leaderTakeoffTime != 0 && xTaskGetTickCount() - leaderTakeoffTime > TUNNEL_ARM_DELAY) {
        DEBUG_PRINT("Leader flying, auto arm!\n");
        tunnelSetDroneState(DRONE_STATE_ARMED);
      }
      break;
    }
    case DRONE_STATE_ARMED: {
      // Launch the relay drone if the leader got too far away
      if((isPeerIDValid(getLeaderID()) && !tunnelIsDroneConnected(getLeaderID())) || 
        (tunnelIsDroneConnected(getLeaderID()) && tunnelGetLeaderSignal()->rssi > TUNNEL_RSSI_ARMED + TUNNEL_RSSI_GROUND_PENALTY)) {
        DEBUG_PRINT("Leader far, auto take off!\n");
        tunnelSetDroneState(DRONE_STATE_FLYING);
      }

      // Launch the base drone when the last drone is flying
      if(tunnelGetDroneRole() == DRONE_ROLE_BASE) {
        DEBUG_PRINT("Launch base!\n");
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
      break;
    }
    case DRONE_STATE_CRASHED:
      tunnelSetDroneState(DRONE_STATE_IDLE); //TODO tests only, remove
      break;
  }
}

// Main tunnel task
static void tunnelTask(void *param) {
  systemWaitStart();
  vTaskDelay(2000);

  // Set the max radio TX Power
  radiolinkSetPowerDbm(4);

  // Initialize LEDs for our use case
  ledseqStop(SYS_LED, seq_calibrated);
  ledseqStop(SYS_LED, seq_alive);
  ledSet(LED_BLUE_L, false);
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
    else if(tunnelGetDroneMode() == DRONE_MODE_MANUAL) {
      if(tunnelGetDroneState() == DRONE_STATE_ARMED)
        tunnelSetDroneState(DRONE_STATE_IDLE);
    }

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

