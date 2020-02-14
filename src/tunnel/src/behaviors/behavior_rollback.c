#include "behavior_rollback.h"
#include "tunnel_behavior.h"
#include "tunnel_signal.h"
#include "tunnel_config.h"

#define DEBUG_MODULE "BEH_ROL"
#include "debug.h"

void behaviorRollbackInit() {
  DEBUG_PRINT("Rollback...\n");
}

void behaviorRollbackUpdate(TunnelSetpoint *vel, bool *enableCollisions) {
  // Hover for now
  behaviorHoverUpdate(vel, enableCollisions);

  // Except move backwards
  vel->vx = -TUNNEL_DEFAULT_SPEED;

  if(tunnelIsDroneConnected(getFollowerID()))
    tunnelSetBehavior(TUNNEL_BEHAVIOR_POSITIONING);
}