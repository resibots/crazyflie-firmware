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
 */

#include "tunnel_relay.h"

#include "tunnel_signal.h"

void tunnelSendP2PPacket(P2PPacket *p) {
  
}

void tunnelSendCRTPPacket(CRTPPacket *p) {

}

void tunnelRelayInit() {

}

bool tunnelRelayTest() {
    return true;
}