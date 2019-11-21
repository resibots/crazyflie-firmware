#ifndef __BEHAVIORIDLE_H
#define __BEHAVIORIDLE_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"
#include "tunnel_behavior.h"

// Function called when this behavior starts
void behaviorIdleInit();

// Function called at each tunnel loop when this behavior is active
void behaviorIdleUpdate(TunnelHover *vel, bool *enableCollisions);

#endif