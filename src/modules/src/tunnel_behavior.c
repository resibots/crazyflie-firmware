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

#include "debug.h"
#define DEBUG_MODULE "BEH"

#include "FreeRTOS.h"
#include "task.h"

#include "estimator_kalman.h"

static TunnelBehavior currentBehavior;

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
    vel->vx = 0.3f;
  else if(gotoGoal - tunnelDistance < -0.05f)
    vel->vx = -0.3f;
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
    zTarget += TAKE_OFF_VELOCITY * (xTaskGetTickCount() - prevTime) / 1000;
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