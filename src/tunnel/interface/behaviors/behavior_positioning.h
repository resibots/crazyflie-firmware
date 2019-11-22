#ifndef __BEHAVIORPOSITIONING_H
#define __BEHAVIORPOSITIONING_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"
#include "tunnel_behavior.h"

// Function called when this behavior starts
void behaviorPositioningInit();

// Function called at each tunnel loop when this behavior is active
void behaviorPositioningUpdate(TunnelSetpoint *vel, bool *enableCollisions);

#endif