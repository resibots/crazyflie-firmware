#ifndef __TUNNELAVOIDER_H
#define __TUNNELAVOIDER_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"

// Check if the deck is working, if not warn it through an LED and skip
bool tunnelAvoiderCheckDeck();

// Initialize scan behavior
void tunnelBehaviorScanEnable();

// Update scan behavior
void tunnelBehaviorScanUpdate(TunnelHover *vel, bool *enableCollisions);

// Update function that needs to be called regularly
void tunnelAvoiderUpdate(TunnelHover *vel, bool enableCollisions);

// Initialize the avoider submodule
void tunnelAvoiderInit(void);

// Test if the avoider submodule initialized successfully
bool tunnelAvoiderTest(void);

#endif