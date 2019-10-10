#ifndef __TUNNELBEHAVIOR_H
#define __TUNNELBEHAVIOR_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"

// Update function that needs to be called regularly
void tunnelBehaviorUpdate(TunnelHover *vel);

// Initialize the behavior submodule
void tunnelBehaviorInit();

// Test if the behavior submodule initialized successfully
bool tunnelBehaviorTest();

#endif