#include "behavior_rollback.h"
#include "tunnel_behavior.h"

#define DEBUG_MODULE "BEH_ROL"
#include "debug.h"

void behaviorRollbackInit() {
  DEBUG_PRINT("Rollback...\n");
}

void behaviorRollbackUpdate(TunnelHover *vel, bool *enableCollisions) {
  tunnelSetPreviousBehavior(); //TODO implement
}