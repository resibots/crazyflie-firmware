#include "behavior_idle.h"
#include "tunnel_behavior.h"

#include "tunnel.h"

#define DEBUG_MODULE "BEH_IDLE"
#include "debug.h"

void behaviorIdleInit() {
  DEBUG_PRINT("Motors off.\n");
  tunnelSetDroneState(DRONE_STATE_IDLE);
}

void behaviorIdleUpdate(TunnelSetpoint *vel, bool *enableCollisions) {
  // Inactive axis
  vel->vx = 0;
  vel->vy = 0;
  vel->yawrate = 0;
  vel->zDistance = 0;

  // No active axis

  // Collisions
  *enableCollisions = false;

  // No transitions
}