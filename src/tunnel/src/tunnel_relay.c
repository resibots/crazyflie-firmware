/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_relay.c - Submodule for relaying packets through the chain. 
 * 
 * CRTP and P2P Tunnel packets should be sent through this submodule (and not directly
 * in p2p.c), it will send the packet to the furthest available drone to make the 
 * smallest amount of jumps possible before reaching the final destination.
 * 
 * When a relay packet has reached its final destination, the packet is transformed
 * back to a regular packet and sent to the main P2P/CRTP queues.
 */

#include "tunnel_relay.h"

#include "FreeRTOS.h"
#include "task.h"

#include "tunnel_config.h"
#include "tunnel_signal.h"
#include "tunnel_comm.h"

#define DEBUG_MODULE "REL"
#include "debug.h"
#include "led.h"
#include "ledseq.h"

//TODO handle packet max size errors
//TODO find a way to send to the PC from any drone?

// Returns true if the destination is our follower or leader
// or if we received a good rssi from the destination not long ago
static bool isDestinationNear(uint8_t destination) {
  if(destination == getLeaderID() || destination == getFollowerID())
    return true;
  if(destination == getDroneId() + 1 || (getDroneId() > 0 && destination == getDroneId() - 1))
    return true;
  return tunnelIsDroneConnected(destination);
}

// Select the furthest destination possible from us (or the destination itself)
static uint8_t selectFurthestDestination(uint8_t destination) {
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

// We received a Relay Rx packet and transform to a P2P Tx packet
// Will be sent to the final destination
static void transformRelayRxToP2PTx(P2PPacket* p) {
  p->header = p->rxdata[p->size - 1];
  p->size--;
  memcpy(p->txdata, p->rxdata, p->size);
}

// We want to send a Relay Tx packet and transform from a P2P Tx packet
static void transformP2PTxToRelayTx(P2PPacket* p, uint8_t relayID) {
  if(p->size >= P2P_MAX_DATA_SIZE)
    return;
  p->txdata[p->size++] = p->header;
  p->txdest = relayID;
  p->port = P2P_PORT_RELAY;
}

// A Relay Rx message is sent to another relay
static void transformRelayRxToRelayTx(P2PPacket* p) {
  // Change packet destination to the furthest available drone
  uint8_t finalDest = p->rxdata[p->size - 1] >> 4 & 0x0F;
  p->txdest = selectFurthestDestination(finalDest);

  p->port = P2P_PORT_RELAY;
  memcpy(p->txdata, p->rxdata, p->size);
}

// Packet callbacks

static void tunnelP2PRelayHandler(P2PPacket *p) {
  // Filter relay packets that are not for this drone
  if(p->rxdest != getDroneId())
    return;
  
  uint8_t finalDest = p->rxdata[p->size - 1] >> 4 & 0x0F;
  // DEBUG_PRINT("Got relay P2P from %i, final=%i\n", p->origin, finalDest);
  // p2pPrintPacket(p, true);
  if(finalDest == getDroneId()) {
    // A relay packet should not reach final destination, must arrive as a regular P2P packet
    DEBUG_PRINT("WARNING Dropping relay, reached dest\n");
    return;
  }

  // If the final destination is near, transform it to a regular P2P packet 
  // and send it to the final drone as a regular P2P Packet
  if(isDestinationNear(finalDest)) {
    transformRelayRxToP2PTx(p);
    // DEBUG_PRINT("Relaying P2P to final %i\n", p->txdest);
    // p2pPrintPacket(p, false);
    p2pSendPacket(p);
  }

  // If the packet has not reached its destination yet, find the furthest relay
  // available and send the packet to it
  else {
    transformRelayRxToRelayTx(p);
    // DEBUG_PRINT("Relaying P2P to relay %i\n", p->txdest);
    // p2pPrintPacket(p, false);
    p2pSendPacket(p);
  }
}

static void tunnelP2PTraceHandler(P2PPacket* p) {
  //TODO handle a new trace packet
}

static void tunnelP2PCrtpHandler(P2PPacket *p) {
  uint8_t directionFlag = p->rxdata[1] & 0x10;

  // Received a base-to-drone packet
  if(directionFlag) {
    CRTPTunnelPacket p_crtp;
    p_crtp.header = p->rxdata[0];
    memcpy(p_crtp.context, &p->rxdata[1], p->size);
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
  if(p->txdest == getDroneId())
    return false;

  // If the drone is our neighbor or near, send a direct P2P packet
  if(isDestinationNear(p->txdest)) {
    if(p->size >= P2P_MAX_DATA_SIZE)
      return false;
    // DEBUG_PRINT("Sending direct P2P to %i\n", p->txdest);
    // p2pPrintPacket(p, false);
    return p2pSendPacket(p);
  }
  // If not, initiate a relay chain and send the first relay packet
  else {
    if(p->size >= P2P_MAX_DATA_SIZE)
      return false;
    transformP2PTxToRelayTx(p, selectFurthestDestination(p->txdest));
    // DEBUG_PRINT("Sending relay P2P to %i\n", p->txdest);
    // p2pPrintPacket(p, false);
    return p2pSendPacket(p);
  }
  return true;
}

// Send a packet to all drones between us and the destination
bool tunnelTraceP2PPacket(P2PPacket *p, TraceMode mode) {
  // Fill the correct destination
  switch(mode) {
    case TRACE_MODE_FORWARD:
      p->txdest = 0;
    case TRACE_MODE_BACKWARD:
      p->txdest = getNDrones() - 1;
    case TRACE_MODE_ALL:
      return tunnelTraceP2PPacket(p, TRACE_MODE_BACKWARD) & 
             tunnelTraceP2PPacket(p, TRACE_MODE_FORWARD);
  }

  // Prepare the packet tracing
  //TODO

  return tunnelSendP2PPacket(p);
}

bool tunnelSendCRTPPacketToBase(CRTPTunnelPacket *p) {
  if(tunnelIsBaseConnected() || getBaseDroneID() == getDroneId())
    crtpSendPacket(p);
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
  if(p->destination != getDroneId()) {
    P2PPacket p_p2p;
    p_p2p.port = P2P_PORT_CRTP;
    p_p2p.txdest = p->destination;
    p_p2p.txdata[0] = p->header;
    p_p2p.txdata[1] = p->context;
    memcpy(&p_p2p.txdata[2], p->dronedata, p->size);
    p_p2p.size = 2/*header+context*/ + p->size/*data*/;
    return tunnelSendP2PPacket(&p_p2p);
  } 
  else
    ledseqRun(SYS_LED, seq_testPassed);
}

void tunnelRelayInit() {
  p2pRegisterPortCB(P2P_PORT_RELAY, tunnelP2PRelayHandler);
  p2pRegisterPortCB(P2P_PORT_TRACE, tunnelP2PTraceHandler);
  p2pRegisterPortCB(P2P_PORT_CRTP,  tunnelP2PCrtpHandler);
}

bool tunnelRelayTest() {
    return true;
}