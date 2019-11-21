#include "behavior_positioning.h"
#include "tunnel_behavior.h"

#include "tunnel_config.h"
#include "tunnel_signal.h"

#define DEBUG_MODULE "BEH_POS"
#include "debug.h"

#define TUNNEL_SIGNAL_DIFF_TOLERANCE 3

void behaviorPositioningInit() {
  DEBUG_PRINT("Starting positioning\n");
}

void behaviorPositioningUpdate(TunnelHover *vel, bool *enableCollisions) {
  // Inactive axis
  vel->vy = 0;
  vel->yawrate = 0;
  vel->zDistance = TUNNEL_DEFAULT_HEIGHT;

  // Active axis
  SignalLog *followerSignal = (getDroneId() < getNDrones() - 1) ? tunnelGetFollowerSignal() : tunnelGetBaseSignal();
  SignalLog *leaderSignal   = tunnelGetLeaderSignal();

  //TODO If the last RSSI value is too old, consider connection lost
  // if(isPeerIDValid(getLeaderID()) && !tunnelIsDroneConnected(getLeaderID()))
  //   tunnelSetBehavior(TUNNEL_BEHAVIOR_RECONNECT);
  // if(isPeerIDValid(getFollowerID()) && !tunnelIsDroneConnected(getFollowerID()))
  //   tunnelSetBehavior(TUNNEL_BEHAVIOR_ROLLBACK);

  // Don't go too close to another drone
  if(leaderSignal->rssi < TUNNEL_RSSI_BEST)
    vel->vx = -TUNNEL_DEFAULT_SPEED;
  else if(followerSignal->rssi < TUNNEL_RSSI_BEST)
    vel->vx = TUNNEL_DEFAULT_SPEED;
  else {
    // Move forward or backward to reach the destination
    float signalDiff = leaderSignal->rssi - followerSignal->rssi;
    if(signalDiff > TUNNEL_SIGNAL_DIFF_TOLERANCE / 2.f)
    vel->vx = TUNNEL_DEFAULT_SPEED;
    else if(signalDiff < -TUNNEL_SIGNAL_DIFF_TOLERANCE / 2.f)
    vel->vx = -TUNNEL_DEFAULT_SPEED;
    else vel->vx = 0;
  }

  // Collisions
  *enableCollisions = true;

  // No transitions
}