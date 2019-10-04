#ifndef __TUNNELCOMMANDER_H
#define __TUNNELCOMMANDER_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "crtp.h"

// Send a hover setpoint to the drone's stabilizer
void sendSetpointHover(float vx,float vy, float yawrate, float zDistance);

// Send a stop setpoint to the drone's stabilizer
void sendSetpointStop();

// Update function that needs to be called regularly
void tunnelCommanderUpdate();

// Process an incoming CRTPPacket concerning setpoints
void crtpTunnelCommanderHandler(CRTPPacket *p);

// Initialize the commander submodule
void tunnelCommanderInit();

// Test if the commander submodule initialized successfully
bool tunnelCommanderTest();

#endif