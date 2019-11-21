#ifndef __BEHAVIORHOVER_H
#define __BEHAVIORHOVER_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"
#include "tunnel_behavior.h"

// Function called when this behavior starts
void behaviorHoverInit();

// Function called at each tunnel loop when this behavior is active
void behaviorHoverUpdate(TunnelHover *vel, bool *enableCollisions);

#endif