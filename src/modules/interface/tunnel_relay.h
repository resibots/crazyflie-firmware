#ifndef __TUNNELRELAY_H
#define __TUNNELRELAY_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "p2p.h"
#include "crtp.h"

// Send a regular P2P packet. It will go through the least amount of drones possible
bool tunnelSendP2PPacket(P2PPacket *p);

// Send a regular CRTP packet. It will go through the least amount of drones possible
bool tunnelSendCRTPPacket(CRTPPacket *p);

// Initialize the param submodule
void tunnelRelayInit();

// Test if the param submodule initialized successfully
bool tunnelRelayTest();

#endif