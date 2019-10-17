/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_behavior.c - Submodule that applies the correct movement policy 
 *                     and manages behavior changes. Returns the desired movement.
 * 
 * Is part of the navigation stack (commander, avoider & behavior).
 */

#include "tunnel_behavior.h"
#include "tunnel_config.h"
#include "tunnel_commander.h"
#include "tunnel_signal.h"

#include "debug.h"
#define DEBUG_MODULE "BEH"

#include "FreeRTOS.h"
#include "task.h"
#include "led.h"

#include "estimator_kalman.h"

static TunnelBehavior currentBehavior;

// Signal middle Behavior

#define TUNNEL_SIGNAL_DIFF_TOLERANCE 10
#define TUNNEL_SIGNAL_TIMEOUT 1000

static void tunnelBehaviorSignalMiddleUpdate(TunnelHover *vel, bool *enableCollisions) {
  // Don't move on other axis
  vel->vy = 0;
  vel->yawrate = 0;
  vel->zDistance = TUNNEL_DEFAULT_HEIGHT;

  SignalLog *followerSignal = (getDroneId() >= getNDrones() - 1) ? tunnelGetFollowerSignal() : tunnelGetBaseSignal();

  // If the last RSSI value is too old, consider connection lost
  if(xTaskGetTickCount() - tunnelGetLeaderSignal()->timestamp > TUNNEL_SIGNAL_TIMEOUT)
    setTunnelCanFly(false); // TODO wait for reconnect behavior
  if(xTaskGetTickCount() - followerSignal->timestamp > TUNNEL_SIGNAL_TIMEOUT)
    setTunnelCanFly(false); // TODO rollback behavior

  //Don't go too close to another drone
  if(tunnelGetLeaderSignal()->rssi < TUNNEL_RSSI_BEST)
    vel->vx = -TUNNEL_DEFAULT_SPEED;
  else if(followerSignal->rssi < TUNNEL_RSSI_BEST)
    vel->vx = TUNNEL_DEFAULT_SPEED;
  else {
    // Move forward or backward to reach the destination
    float signalDiff = tunnelGetLeaderSignal()->rssi - followerSignal->rssi;
    if(signalDiff > TUNNEL_SIGNAL_DIFF_TOLERANCE / 2)
      vel->vx = TUNNEL_DEFAULT_SPEED;
    else if(signalDiff < -TUNNEL_SIGNAL_DIFF_TOLERANCE / 2)
      vel->vx = -TUNNEL_DEFAULT_SPEED;
    else vel->vx = 0;
  }

  // Status LED, green if we consider ourselves in the middle
  ledSet(LED_GREEN_R, vel->vx == 0);
}

// Goto Behavior

static float gotoGoal = 0;

void setBehaviorGotoGoal(float goal) {
  gotoGoal = goal;
}

static void tunnelBehaviorGotoUpdate(TunnelHover *vel, bool *enableCollisions) {
  // Don't move on other axis
  vel->vy = 0;
  vel->yawrate = 0;
  vel->zDistance = TUNNEL_DEFAULT_HEIGHT;

  // Move forward or backward to reach the destination
  float tunnelDistance = tunnelGetDistance();
  if(gotoGoal - tunnelDistance > 0.05f)
    vel->vx = TUNNEL_DEFAULT_SPEED;
  else if(gotoGoal - tunnelDistance < -0.05f)
    vel->vx = -TUNNEL_DEFAULT_SPEED;
  else tunnelSetBehavior(TUNNEL_BEHAVIOR_HOVER);
}

// Take off Behavior

static float zTarget = 0.1f;
static unsigned long prevTime = 0;

static void tunnelBehaviorTakeOffUpdate(TunnelHover *vel, bool *enableCollisions) {
  // Don't move on other axis
  vel->vx = 0;
  vel->vy = 0;
  vel->yawrate = 0;

  // Disable collisions during takeoff
  *enableCollisions = false;

  // Slowly increase the height
  if(xTaskGetTickCount() > prevTime + 100) {
    zTarget += TAKE_OFF_VELOCITY * (float)(xTaskGetTickCount() - prevTime) / 1000.f;
    prevTime = xTaskGetTickCount();
  }
  vel->zDistance = zTarget;

  // End the behavior when the default height is reached
  if(zTarget >= TUNNEL_DEFAULT_HEIGHT) {
    vel->zDistance = TUNNEL_DEFAULT_HEIGHT;
    tunnelSetBehavior(TUNNEL_BEHAVIOR_HOVER);
  }
}

// Main functions

void tunnelBehaviorUpdate(TunnelHover *vel, bool *enableCollisions) {
  switch (currentBehavior) {
    case TUNNEL_BEHAVIOR_LAND: //TODO
    case TUNNEL_BEHAVIOR_IDLE:
      vel->vx = 0;
      vel->vy = 0;
      vel->yawrate = 0;
      vel->zDistance = 0;

      *enableCollisions = false;
      break;
    case TUNNEL_BEHAVIOR_TAKE_OFF:
      tunnelBehaviorTakeOffUpdate(vel, enableCollisions);
      break;
    case TUNNEL_BEHAVIOR_HOVER:
      vel->vx = 0;
      vel->vy = 0;
      vel->yawrate = 0;
      vel->zDistance = TUNNEL_DEFAULT_HEIGHT;

      *enableCollisions = true;
      break;
    case TUNNEL_BEHAVIOR_GOTO:
      tunnelBehaviorGotoUpdate(vel, enableCollisions);
      break;
    case TUNNEL_BEHAVIOR_SIGNAL_MIDDLE:
      tunnelBehaviorSignalMiddleUpdate(vel, enableCollisions);
      break;
  }
}

void tunnelSetBehavior(TunnelBehavior behavior) {
  if(behavior != currentBehavior) {
    if(behavior == TUNNEL_BEHAVIOR_TAKE_OFF) {
      zTarget = 0.1f;
      estimatorKalmanInit();
    }
  }
  currentBehavior = behavior;
}

// Submodule initialization

void tunnelBehaviorInit() {
  currentBehavior = TUNNEL_BEHAVIOR_IDLE;
}

bool tunnelBehaviorTest() {
  return true;
}