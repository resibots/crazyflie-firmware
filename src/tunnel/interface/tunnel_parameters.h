#ifndef __TUNNELPARAMETERS_H
#define __TUNNELPARAMETERS_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "crtp.h"

// Handle CRTP parameters requests (must be called in the main callback)
void crtpTunnelParametersHandler(CRTPPacket *p);

// Initialize the param submodule
void tunnelParametersInit();

// Test if the param submodule initialized successfully
bool tunnelParametersTest();

#endif