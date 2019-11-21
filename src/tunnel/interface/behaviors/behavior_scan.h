#ifndef __BEHAVIORSCAN_H
#define __BEHAVIORSCAN_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"
#include "tunnel_behavior.h"

// Function called when this behavior starts
void behaviorScanInit();

// Function called at each tunnel loop when this behavior is active
void behaviorScanUpdate(TunnelHover *vel, bool *enableCollisions);

#endif