/**
* LARSEN Research team - INRIA
* Multi-agent tunnel exploration module
* 
* author: Pierre Laclau <pierre.laclau@etu.utc.fr>
* maintainer: LARSEN, INRIA Nancy Grand-Est, France
*
* tunnel_relay.c - Submodule for sending & relaying packets through the chain. 
* 
* CRTP and P2P Tunnel packets should be sent through this submodule (and not directly
* in p2p.c or crtp.c), it will send the packet to the furthest available drone in order 
* to make the smallest amount of jumps possible before reaching the final destination.
* 
* When a relay packet has reached its final destination, the packet is transformed
* back to a regular packet and sent to the drone's main P2P/CRTP queues.
*/

#include "tunnel_relay.h"

#include "FreeRTOS.h"
#include "task.h"

#include "tunnel_config.h"
#include "tunnel_signal.h"
#include "tunnel_comm.h"
#include "radiolink.h"

#define DEBUG_MODULE "REL"
#include "debug.h"
#include "led.h"
#include "ledseq.h"

// Returns true if the destination is our follower or leader
// or if we received a good rssi from the destination not long ago
static bool isDestinationNear(uint8_t destination) {
  if(destination == getLeaderID() || destination == getFollowerID())
    return true; // Leader and follower are always considered close
  if(destination == getDroneId() + 1 || (getDroneId() > 0 && destination == getDroneId() - 1))
    return true; // ID+1 and ID-1 are always considered close
  return tunnelIsDroneConnected(destination);
}

// Select the furthest destination possible from us (or the destination itself)
static uint8_t selectFurthestDestination(uint8_t destination) {
  // Infinite loop protection
  if(destination == getDroneId())
    return getDroneId();

  int8_t direction = (destination - getDroneId() > 0) ? 1 : -1;

  int8_t stepDest = getDroneId() + direction;
  uint8_t best = stepDest; // If no one's near, send to our neighbor by default (with hope it'll get the message)
  while(stepDest != destination) {
    stepDest += direction;
    if(isDestinationNear(stepDest))
      best = stepDest;
  }
  return best;
}

// Packet callbacks

static void tunnelP2PRelayHandler(P2PPacket *p) {
  // Filter relay packets that are not for this drone
  if(p->rxdest != getDroneId())
    return;
  
  uint8_t finalDest = p->rxdata[p->size - 1] >> 4 & 0x0F;

  // A relay packet should not reach final destination, must arrive as a regular P2P packet
  if(finalDest == getDroneId()) {
    DEBUG_PRINT("WARNING Dropping relay\n");
    return;
  }

  // If the final destination is near, transform it to a regular P2P packet 
  // and send it to the final drone as a regular P2P Packet
  if(isDestinationNear(finalDest)) {
    p->header = p->rxdata[p->size - 1];
    p->size--;
    memcpy(p->txdata, p->rxdata, p->size);
    p2pSendPacket(p);
  }

  // If the packet has not reached its destination yet, find the furthest relay available and send the packet to it
  else {
    // Change packet destination to the furthest available drone
    uint8_t finalDest = p->rxdata[p->size - 1] >> 4 & 0x0F;
    p->txdest = selectFurthestDestination(finalDest);
    p->port = P2P_PORT_RELAY;
    memcpy(p->txdata, p->rxdata, p->size);
    p2pSendPacket(p);
  }
}

static void tunnelP2PTraceHandler(P2PPacket* p) {
  if(p->rxdest == getDroneId()) {
    // Send the paquet to our P2P queue
    p->header = p->rxdata[p->size - 1];
    p->size--;

    // Send the packet to this drone's regular P2P port
    radiolinkSendP2PPacketToQueue(p);

    // Send the paquet to the next drone if needed
    int8_t finalDest = p->rxdata[p->size++] >> 4 & 0x0F;
    if(finalDest != getDroneId()) {
      int8_t direction = (finalDest - (int8_t)getDroneId() > 0) ? 1 : -1;
      p->txdest = getDroneId() + direction;
      p->port = P2P_PORT_TRACE;
      memcpy(p->txdata, p->rxdata, p->size);
      tunnelSendP2PPacket(p);
    }
  }
}

static void tunnelP2PCrtpHandler(P2PPacket *p) {
  uint8_t directionFlag = p->rxdata[1] & 0x10;

  // Received a base-to-drone packet
  if(directionFlag) {
    CRTPTunnelPacket p_crtp;
    memcpy(&p_crtp.header, p->rxdata, p->size);
    p_crtp.size = p->size - 2;
    processIncomingCRTPPacket(&p_crtp);
  }
  
  // Received a drone-to-base packet
  else {
    CRTPTunnelPacket p_crtp;
    p_crtp.header = p->rxdata[0];
    memcpy(p_crtp.basedata, &p->rxdata[1], p->size - 1);
    p_crtp.size = p->size - 1;
    crtpSendPacket(&p_crtp);
  }
}

// Public functions

// Send a packet to a drone. Will be relayed by the least amount of drones possible
bool tunnelSendP2PPacket(P2PPacket *p) {
  if(p->size >= P2P_MAX_DATA_SIZE)
    return false;

  if(p->txdest == getDroneId())
    return false;

  // If the drone is our neighbor or near, send a direct P2P packet
  if(isDestinationNear(p->txdest))
    return p2pSendPacket(p);

  // If not, initiate a relay chain and send the first relay packet
  else {
    p->txdata[p->size++] = p->header;
    p->txdest = p->txdest;
    p->port = P2P_PORT_RELAY;
    return p2pSendPacket(p);
  }
}

bool tunnelTraceP2PPacket(P2PPacket *p, TraceMode mode) {
  if(p->size >= P2P_MAX_DATA_SIZE)
    return false;

  // Fill the correct destination
  switch(mode) {
    case TRACE_MODE_FORWARD:
      p->txdest = 0;
      break;
    case TRACE_MODE_BACKWARD:
      p->txdest = getNDrones() - 1;
      break;
    case TRACE_MODE_ALL: {
      P2PPacket p_copy;
      memcpy(&p_copy, p, 2 + p->size); // clean?
      return tunnelTraceP2PPacket(p,       TRACE_MODE_BACKWARD) & 
             tunnelTraceP2PPacket(&p_copy, TRACE_MODE_FORWARD);
    }
  }

  if(p->txdest == getDroneId() || p->size >= P2P_MAX_DATA_SIZE)
    return false;

  // Prepare the packet tracing
  p->txdata[p->size++] = p->header;
  p->txdest = getDroneId() + ((p->txdest - getDroneId() > 0) ? 1 : -1);
  p->port = P2P_PORT_TRACE;

  return tunnelSendP2PPacket(p);
}

bool tunnelSendCRTPPacketToBase(CRTPTunnelPacket *p) {
  if(p->size >= CRTP_MAX_DATA_SIZE)
    return false;

  if(tunnelIsBaseConnected() || getBaseDroneID() == getDroneId())
    return crtpSendPacket(p);
  else { // If we're not connected, send it to the connected drone
    P2PPacket p_p2p;
    p_p2p.port = P2P_PORT_CRTP;
    p_p2p.txdest = getBaseDroneID();
    p_p2p.txdata[0] = p->header;
    memcpy(&p_p2p.txdata[1], p->basedata, p->size);
    p_p2p.txdata[1] &= 0xEF; // Mark the packet as drone-to-base
    p_p2p.size = 1/*header*/ + p->size/*data*/;
    return tunnelSendP2PPacket(&p_p2p);
  }
}

bool tunnelSendCRTPPacketToDrone(CRTPTunnelPacket *p) {
  if(p->size >= CRTP_MAX_DATA_SIZE)
    return false;
  p->direction = 1; //Mark packet as base-to-drone

  // Send a CRTP Packet to a single drone
  if((p->destination & 0x0F) != getDroneId()) {
    P2PPacket p_p2p;
    p_p2p.port = P2P_PORT_CRTP;
    p_p2p.txdest = p->destination;
    memcpy(p_p2p.txdata, &p->header, p->size + 2);
    p_p2p.size = 2/*header+context*/ + p->size/*data*/;
    return tunnelSendP2PPacket(&p_p2p);
  }
  return false;
}

void tunnelRelayInit() {
  p2pRegisterPortCB(P2P_PORT_RELAY, tunnelP2PRelayHandler);
  p2pRegisterPortCB(P2P_PORT_TRACE, tunnelP2PTraceHandler);
  p2pRegisterPortCB(P2P_PORT_CRTP,  tunnelP2PCrtpHandler);
}

bool tunnelRelayTest() {
  return true;
}