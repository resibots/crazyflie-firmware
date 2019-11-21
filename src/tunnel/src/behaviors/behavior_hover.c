#include "behavior_hover.h"
#include "tunnel_behavior.h"

#include "tunnel_config.h"

void behaviorHoverInit() {

}

void behaviorHoverUpdate(TunnelHover *vel, bool *enableCollisions) {
  // Inactive axis
  vel->vx = 0;
  vel->vy = 0;
  vel->yawrate = 0;

  // Active axis
  vel->zDistance = TUNNEL_DEFAULT_HEIGHT;

  // Collisions
  *enableCollisions = true;

  // No transitions
}