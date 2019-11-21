#ifndef __BEHAVIORVERTICAL_H
#define __BEHAVIORVERTICAL_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"
#include "tunnel_behavior.h"

// Function called when this behavior starts
void behaviorTakeOffInit();

// Function called at each tunnel loop when this behavior is active
void behaviorTakeOffUpdate(TunnelHover *vel, bool *enableCollisions);


// Function called when this behavior starts
void behaviorLandInit();

// Function called at each tunnel loop when this behavior is active
void behaviorLandUpdate(TunnelHover *vel, bool *enableCollisions);

#endif