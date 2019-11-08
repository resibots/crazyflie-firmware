#ifndef __TUNNELBEHAVIOR_H
#define __TUNNELBEHAVIOR_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"

// List of available behaviors
typedef enum {
  TUNNEL_BEHAVIOR_IDLE        = 0, // Stay on the ground, motors off
  TUNNEL_BEHAVIOR_TAKE_OFF    = 1, // Take off slowly with a specified velocity
  TUNNEL_BEHAVIOR_HOVER       = 2, // Stay still at the current position
  TUNNEL_BEHAVIOR_GOTO        = 3, // Reach a specified tunnelDistance
  TUNNEL_BEHAVIOR_POSITIONING = 4, // Stay between the leader and follower (RSSI based)
  TUNNEL_BEHAVIOR_SCAN        = 5, // Turn 90 degrees and scan the room, then point to the tunnel
  TUNNEL_BEHAVIOR_LAND        = 6, // Land slowly with a specified velocity
} TunnelBehavior;

// Used for the Goto Behavior only, sets the destination
void setBehaviorGotoGoal(float goal);

// Update function that needs to be called regularly
void tunnelBehaviorUpdate(TunnelHover *vel, bool *enableCollisions);

// Get the current active behavior
TunnelBehavior tunnelGetCurrentBehavior();

// Set the new drone behavior. TODO no init for now
void tunnelSetBehavior(TunnelBehavior behavior);

// Go back to the previous active behavior
// [WARNING] works only one time, will do nothing if repeated without manually changing the current behavior
void tunnelSetPreviousBehavior();

// Initialize the behavior submodule
void tunnelBehaviorInit();

// Test if the behavior submodule initialized successfully
bool tunnelBehaviorTest();

#endif