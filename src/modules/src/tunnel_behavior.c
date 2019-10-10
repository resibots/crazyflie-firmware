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

#include "debug.h"
#define DEBUG_MODULE "BEH"

#include "FreeRTOS.h"
#include "task.h"

#include "led.h"

static float zTarget = 0.1;
static unsigned long prevTime = 0;

static TunnelBehavior currentBehavior;

static void tunnelBehaviorTakeOffUpdate(TunnelHover *vel) {
  // Don't move on other axis
  vel->vx = 0;
  vel->vy = 0;
  vel->yawrate = 0;

  // Slowly increase the height
  if(xTaskGetTickCount() > prevTime + 100) {
    zTarget += TAKE_OFF_VELOCITY * (xTaskGetTickCount() - prevTime) / 1000;
    prevTime = xTaskGetTickCount();
  }
  vel->zDistance = zTarget;

  // End the behavior when the default height is 
  if(zTarget >= TUNNEL_DEFAULT_HEIGHT) {
    zTarget = 0.1;
    vel->zDistance = TUNNEL_DEFAULT_HEIGHT;
    tunnelSetBehavior(TUNNEL_BEHAVIOR_HOVER);
    return;
  }
  tunnelSetBehavior(TUNNEL_BEHAVIOR_TAKE_OFF);
}

void tunnelBehaviorUpdate(TunnelHover *vel) {
  if(currentBehavior == TUNNEL_BEHAVIOR_TAKE_OFF) ledSet(LED_GREEN_R, true);
  else ledSet(LED_GREEN_R, false); //TODO remove

  switch (currentBehavior) {
    case TUNNEL_BEHAVIOR_IDLE:
      vel->vx = 0;
      vel->vy = 0;
      vel->yawrate = 0;
      vel->zDistance = 0;
      break;
    case TUNNEL_BEHAVIOR_TAKE_OFF:
      tunnelBehaviorTakeOffUpdate(vel);
      break;
    case TUNNEL_BEHAVIOR_HOVER:
      vel->vx = 0;
      vel->vy = 0;
      vel->yawrate = 0;
      vel->zDistance = TUNNEL_DEFAULT_HEIGHT;
      break;
  }
}

void tunnelSetBehavior(TunnelBehavior behavior) {
  currentBehavior = behavior;
}

void tunnelBehaviorInit() {
  currentBehavior = TUNNEL_BEHAVIOR_IDLE;
}

bool tunnelBehaviorTest() {
  return true;
}