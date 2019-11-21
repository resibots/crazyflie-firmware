#ifndef __TUNNELAVOIDER_H
#define __TUNNELAVOIDER_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_commander.h"

// Structure for storing all distance ranges in 4 bytes
typedef struct {
uint8_t front;
uint8_t back;
uint8_t left;
uint8_t right;
} HorizontalRanges; // centimeters

// Get the last multiranger distances measurement (centimeters)
HorizontalRanges *tunnelGetRanges();

// Initialize scan behavior
void tunnelBehaviorScanEnable();

// Update scan behavior
void tunnelBehaviorScanUpdate(TunnelHover *vel, bool *enableCollisions);

// Check if the multiranger deck is working, if not warn it through an LED and skip avoiding
bool tunnelAvoiderCheckDeck();

// Update function that needs to be called regularly
void tunnelAvoiderUpdate(TunnelHover *vel, bool enableCollisions);

// Initialize the avoider submodule
void tunnelAvoiderInit(void);

// Test if the avoider submodule initialized successfully
bool tunnelAvoiderTest(void);

#endif