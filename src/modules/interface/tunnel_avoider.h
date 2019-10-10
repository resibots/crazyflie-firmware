#ifndef __TUNNELAVOIDER_H
#define __TUNNELAVOIDER_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"

// Update function that needs to be called regularly
void tunnelAvoiderUpdate(TunnelHover *vel);

// Initialize the avoider submodule
void tunnelAvoiderInit(void);

// Test if the avoider submodule initialized successfully
bool tunnelAvoiderTest(void);

#endif