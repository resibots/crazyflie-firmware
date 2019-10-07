#ifndef __TUNNELAVOIDER_H
#define __TUNNELAVOIDER_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Update function that needs to be called regularly
//TODO return the calculated repulsion force
void tunnelAvoiderUpdate();

// Initialize the avoider submodule
void tunnelAvoiderInit(void);

// Test if the avoider submodule initialized successfully
bool tunnelAvoiderTest(void);

#endif