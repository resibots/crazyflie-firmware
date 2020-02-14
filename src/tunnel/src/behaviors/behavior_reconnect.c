#include "behavior_reconnect.h"
#include "tunnel_behavior.h"
#include "behavior_hover.h"
#include "tunnel_signal.h"
#include "tunnel_config.h"

#define DEBUG_MODULE "BEH_REC"
#include "debug.h"

void behaviorReconnectInit() {
  DEBUG_PRINT("Reconnecting...\n");
}

void behaviorReconnectUpdate(TunnelSetpoint *vel, bool *enableCollisions) {
  // Hover for now
  behaviorHoverUpdate(vel, enableCollisions);

  if(tunnelIsDroneConnected(getLeaderID()))
    tunnelSetBehavior(TUNNEL_BEHAVIOR_POSITIONING);
}