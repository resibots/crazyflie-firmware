#ifndef __TUNNELCOMMANDER_H
#define __TUNNELCOMMANDER_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "crtp.h"

// Common structure used for the navigation stack (commander, avoider & behavior)
typedef struct {
  float vx;           // m/s in the body frame of reference
  float vy;           // m/s in the body frame of reference
  float yawrate;      // deg/s
  float zDistance;    // m in the world frame of reference
} TunnelHover;

// Send a hover setpoint to the drone's stabilizer
void sendSetpointHover(TunnelHover *hover);

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