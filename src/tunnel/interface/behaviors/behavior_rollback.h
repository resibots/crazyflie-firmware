#ifndef __BEHAVIORROLLBACK_H
#define __BEHAVIORROLLBACK_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"
#include "tunnel_behavior.h"

// Function called when this behavior starts
void behaviorRollbackInit();

// Function called at each tunnel loop when this behavior is active
void behaviorRollbackUpdate(TunnelHover *vel, bool *enableCollisions);

#endif