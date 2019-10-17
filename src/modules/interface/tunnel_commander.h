#ifndef __TUNNELCOMMANDER_H
#define __TUNNELCOMMANDER_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "tunnel_helpers.h"
#include "crtp.h"

// Send a hover setpoint to the drone's stabilizer
void sendSetpointHover(TunnelHover *hover);

// Send a stop setpoint to the drone's stabilizer
void sendSetpointStop();

// Get the estimated distance of how deep we are in the tunnel (in meters)
float tunnelGetDistance();

// Get the current applied movement on the drone
TunnelHover *tunnelGetCurrentMovement();

// Update function that needs to be called regularly
void tunnelCommanderUpdate();

// Process an incoming CRTPPacket concerning setpoints
void crtpTunnelCommanderHandler(CRTPPacket *p);

// Initialize the commander submodule
void tunnelCommanderInit();

// Test if the commander submodule initialized successfully
bool tunnelCommanderTest();

#endif