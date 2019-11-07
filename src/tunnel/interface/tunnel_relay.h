#ifndef __TUNNELRELAY_H
#define __TUNNELRELAY_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "p2p.h"
#include "crtp.h"

typedef enum {
    TRACE_MODE_DIRECT,   // Send the packet to all drones between us and the destination
    TRACE_MODE_FORWARD,  // Send the packet to all drones between us and the head drone
    TRACE_MODE_BACKWARD, // Send the packet to all drones between us and the last drone
    TRACE_MODE_ALL       // Send the packet to all other drones
} TraceMode;

// Send a regular P2P packet. It will go through the least amount of drones possible
bool tunnelSendP2PPacket(P2PPacket *p);

// Send a packet to all drones between us and the destination
bool tunnelTraceP2PPacket(P2PPacket *p, TraceMode mode);

// Send a CRTP packet to the base (using the relay layer)
bool tunnelSendCRTPPacketToBase(CRTPTunnelPacket *p);

// New CRTP packet that needs to be sent to another drone than the connected one (using the relay layer)
bool tunnelSendCRTPPacketToDrone(CRTPTunnelPacket *p);

// Initialize the param submodule
void tunnelRelayInit();

// Test if the param submodule initialized successfully
bool tunnelRelayTest();

#endif