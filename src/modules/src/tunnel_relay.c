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

#include "led.h"
#include "ledseq.h"

#define DISCONNECT_TIMEOUT 500

//TODO handle packet max size errors

// Returns true if the destination is our follower or leader
// or if we received a good rssi from the destination not long ago
static bool isDestinationNear(uint8_t destination) {
  if(destination == getLeaderID() || destination == getFollowerID())
    return true;
  SignalLog* s = tunnelGetUnfilteredSignal(destination);
  return s->rssi > 0 && s->rssi < TUNNEL_RSSI_DANGER &&
         (xTaskGetTickCount() - s->timestamp) < DISCONNECT_TIMEOUT;
}

// Select the furthest destination possible from us (or the destination itself)
static uint8_t selectFurthestDestination(uint8_t destination) {
  int8_t direction = (destination - getDroneId() > 0) ? 1 : -1;

  int8_t stepDest = getDroneId() + direction;
  while(!isDestinationNear(stepDest) && stepDest != destination) {
    stepDest += direction;
  }
  return stepDest;
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
  // Change packet destination to the furthest available drone
  uint8_t finalDest = p->rxdata[p->size - 1] >> 4 & 0x0F;
  p->txdest = selectFurthestDestination(finalDest);

  p->port = P2P_PORT_RELAY;
  memcpy(p->txdata, p->rxdata, p->size);
}

bool tunnelSendP2PPacket(P2PPacket *p) {
  // If we are sending a packet to ourselves, send to the P2P queue directly
  if(p->txdest == getDroneId()) {
    //TODO
    return true;
  }

  // If the drone is our neighbor or near, send a direct P2P packet
  if(isDestinationNear(p->txdest)) {
    if(p->size >= P2P_MAX_DATA_SIZE)
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
  return false;
}

static void tunnelP2PRelayHandler(P2PPacket *p) {
  if(p->rxdest == getDroneId()) //TODO handle?
    return;

  // If the relay packet has reached destination, transform it to a regular P2P packet 
  // and send it to the main P2P Queue!
  if(isDestinationNear(p->txdest)) {
    transformRelayRxToP2PTx(p);
    p2pSendPacket(p);
  }

  // If the packet has not reached its destination yet, find the furthest drone available
  // and send the packet to it
  else {
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