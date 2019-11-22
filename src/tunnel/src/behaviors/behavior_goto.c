#include "behavior_goto.h"
#include "tunnel_behavior.h"

#include "tunnel_config.h"

#define DEBUG_MODULE "BEH_GOTO"
#include "debug.h"

static float gotoGoal = 0;
void setBehaviorGotoGoal(float goal) { gotoGoal = goal; }

void behaviorGotoInit() {
  DEBUG_PRINT("Going to d=%.2f\n", gotoGoal);
}

void behaviorGotoUpdate(TunnelSetpoint *vel, bool *enableCollisions) {
  // Inactive axis
  vel->vy = 0;
  vel->yawrate = 0;
  vel->zDistance = TUNNEL_DEFAULT_HEIGHT;

  // Active axis: move forward or backward to reach the destination
  float tunnelDistance = tunnelGetDistance();
  if(gotoGoal - tunnelDistance > 0.05f)
      vel->vx = TUNNEL_DEFAULT_SPEED;
  else if(gotoGoal - tunnelDistance < -0.05f)
      vel->vx = -TUNNEL_DEFAULT_SPEED;
  else {
    DEBUG_PRINT("Reached goal\n");
    tunnelSetBehavior(TUNNEL_BEHAVIOR_HOVER);
  }

  // Collisions
  *enableCollisions = true;

  // No transitions
}