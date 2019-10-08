#ifndef __TUNNELBEHAVIOR_H
#define __TUNNELBEHAVIOR_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Update function that needs to be called regularly
//TODO return the calculated desired force
void tunnelBehaviorUpdate();

// Initialize the behavior submodule
void tunnelBehaviorInit();

// Test if the behavior submodule initialized successfully
bool tunnelBehaviorTest();

#endif