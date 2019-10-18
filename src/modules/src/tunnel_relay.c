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

#include "tunnel_config.h"
#include "tunnel_signal.h"

//TODO handle packet max size errors

static uint8_t selectFurthestDestination(uint8_t destination) {
  int8_t distance = destination - getDroneId();

  // If the destination is our neighbor, send it directly
  // TODO send directly instead of relay
  if(destination == getLeaderID() || destination == getFollowerID())
    return destination;
  //TODO finish
}

static bool isDestinationNear(uint8_t destination) {
  return true; //TODO finish
}

// We received a Relay Rx packet and transform to a P2P Tx packet
// Will be sent to the final destination
static void transformRelayRxToP2PTx(P2PPacket* p) {
  p->header = p->rxdata[p->size - 1];
  p->size--;
  memcpy(p->txdata, p->rxdata, p->size); //TODO MAYBE A COPY BUG ?
}

// We want to send a Relay Tx packet and transform from a P2P Tx packet
static void transformP2PTxToRelayTx(P2PPacket* p, uint8_t relayID) {
  if(p->size >= P2P_MAX_DATA_SIZE)
    return;
  p->txdata[p->size] = p->header;
  p->size++;
  p->txdest = relayID;
  p->port = P2P_PORT_RELAY;
}

// A Relay Rx message is sent to another relay
static void transformRelayRxToRelayTx(P2PPacket* p) {
  //TODO 
}

bool tunnelSendP2PPacket(P2PPacket *p) {
  // If the drone is near enough, send a direct P2P packet
  if(isDestinationNear(p->txdest)) {
    if(p->size <= P2P_MAX_DATA_SIZE)
      return false;
    p2pSendPacket(p);
  }
  // If not, initiate a relay chain and send the first relay packet
  else {
    if(p->size >= P2P_MAX_DATA_SIZE)
      return false;
    transformP2PTxToRelayTx(p, selectFurthestDestination(p->txdest));
    p2pSendPacket(p);
  }
  return true;
}

bool tunnelSendCRTPPacket(CRTPPacket *p) {
  //TODO handle CRTP here?
}

static void tunnelP2PRelayHandler(P2PPacket *p) {
  // If the relay packet has reached destination, transform it to a regular P2P packet 
  // and send it to the main P2P Queue!
  if(isDestinationNear(p->txdest)) {
    transformRelayRxToP2PTx(p);
    p2pSendPacket(p);
  }

  // If the packet has not reached its destination yet, find the furthest drone available
  // and send the packet to it
  else {
    uint8_t finalDest = p->rxdata[p->size - 1] >> 4 & 0x0F;
    p->txdest = selectFurthestDestination(finalDest);
    transformRelayRxToRelayTx(p);
    p2pSendPacket(p);
  }
}

void tunnelRelayInit() {
  p2pRegisterPortCB(P2P_PORT_RELAY, tunnelP2PRelayHandler);
}

bool tunnelRelayTest() {
    return true;
}