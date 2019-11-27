#include "behavior_rollback.h"
#include "tunnel_behavior.h"

#define DEBUG_MODULE "BEH_ROL"
#include "debug.h"

void behaviorRollbackInit() {
  DEBUG_PRINT("Rollback...\n");
}

void behaviorRollbackUpdate(TunnelSetpoint *vel, bool *enableCollisions) {
  tunnelSetBehavior(TUNNEL_BEHAVIOR_LAND); //TODO implement
}