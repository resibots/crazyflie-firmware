#ifndef __BEHAVIORGOTO_H
#define __BEHAVIORGOTO_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"
#include "tunnel_behavior.h"

// Set the tunnel distance to reach
void setBehaviorGotoGoal(float goal);

// Function called when this behavior starts
void behaviorGotoInit();

// Function called at each tunnel loop when this behavior is active
void behaviorGotoUpdate(TunnelHover *vel, bool *enableCollisions);

#endif