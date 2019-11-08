#ifndef __TUNNELPING_H
#define __TUNNELPING_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "crtp.h"

// Update function that needs to be called regularly
void tunnelPingUpdate();

// Process an incoming CRTPTunnelPacket concerning pings
void crtpTunnelPingHandler(CRTPTunnelPacket *p);

// Initialize the ping submodule
void tunnelPingInit();

// Test if the ping submodule initialized successfully
bool tunnelPingTest();

#endif