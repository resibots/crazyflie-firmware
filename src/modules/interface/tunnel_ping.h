#ifndef __TUNNELPING_H
#define __TUNNELPING_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "crtp.h"

// Send a ping through the chain
// TODO mors params to choose the destination drone
void sendPing(bool propagate);

// Update function that needs to be called regularly
void tunnelPingUpdate();

// Callback that needs to be called when receiving a CRTP
// tunnel packet.
void crtpTunnelPingHandler(CRTPPacket *p);

// Initialize the ping submodule
void tunnelPingInit();

// Test if the ping submodule initialized successfully
bool tunnelPingTest();

#endif