#ifndef __BEHAVIORRECONNECT_H
#define __BEHAVIORRECONNECT_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"
#include "tunnel_behavior.h"

// Function called when this behavior starts
void behaviorReconnectInit();

// Function called at each tunnel loop when this behavior is active
void behaviorReconnectUpdate(TunnelSetpoint *vel, bool *enableCollisions);

#endif