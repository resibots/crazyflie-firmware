#include "behavior_idle.h"
#include "tunnel_behavior.h"

#include "tunnel.h"

void behaviorIdleInit() {
  tunnelSetDroneState(DRONE_STATE_IDLE);
}

void behaviorIdleUpdate(TunnelHover *vel, bool *enableCollisions) {
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