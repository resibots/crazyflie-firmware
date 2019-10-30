#ifndef __TUNNELCOMM_H
#define __TUNNELCOMM_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Add the drone's status information in an array (usually a packet)
// Returns the number of bytes used
uint8_t appendStatusMessage(uint8_t *pkData);

// Update function that needs to be called regularly
void tunnelCommUpdate();

// Initialize the comm submodule
void tunnelCommInit();

// Test if the comm submodule initialized successfully
bool tunnelCommTest();

#endif