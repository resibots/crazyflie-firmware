#ifndef __TUNNELBEHAVIOR_H
#define __TUNNELBEHAVIOR_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_helpers.h"

// List of available behaviors
typedef enum {
  TUNNEL_BEHAVIOR_IDLE = 0, // Stay on the ground, motors off
  TUNNEL_BEHAVIOR_TAKE_OFF, // Take off slowly with a specified velocity
  TUNNEL_BEHAVIOR_HOVER,    // Stay still at the current position
  TUNNEL_BEHAVIOR_LAND      // Land slowly with a specified velocity
} TunnelBehavior;

// Update function that needs to be called regularly
void tunnelBehaviorUpdate(TunnelHover *vel);

// Set the new drone behavior. TODO no init for now
void tunnelSetBehavior(TunnelBehavior behavior);

// Initialize the behavior submodule
void tunnelBehaviorInit();

// Test if the behavior submodule initialized successfully
bool tunnelBehaviorTest();

#endif