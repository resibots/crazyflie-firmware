#include "behavior_reconnect.h"
#include "tunnel_behavior.h"

#define DEBUG_MODULE "BEH_REC"
#include "debug.h"

void behaviorReconnectInit() {
  DEBUG_PRINT("Reconnecting...\n");
}

void behaviorReconnectUpdate(TunnelSetpoint *vel, bool *enableCollisions) {
  tunnelSetBehavior(TUNNEL_BEHAVIOR_LAND); //TODO implement
}