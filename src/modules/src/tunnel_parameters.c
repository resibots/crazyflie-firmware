/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_param.c - Submodule for setting and sending tunnel epxloration
 *                  related parameters (e.g. number of drones in the chain)
 */

#include "tunnel_parameters.h"
#include "tunnel_config.h"

#include "p2p.h"
#include "led.h"

typedef enum {
  TUNNEL_PARAM_NDRONES = 0x00,
  TUNNEL_PARAM_CANFLY  = 0x01
} TunnelParameter;

void crtpTunnelParametersHandler(CRTPPacket *p) {
  switch(p->data[0]) {
    case TUNNEL_PARAM_NDRONES:
      setNDrones(p->data[1]);

      // Broadcast the new number of drones to the other drones
      P2PPacket p2p_p;
      p2p_p.txdest = 0x0F; // broadcast
      p2p_p.port   = P2P_PORT_PARAM;
      p2p_p.txdata[0] = getNDrones();
      p2p_p.size = 1;
      p2pSendPacket(&p2p_p);
      p2pSendPacket(&p2p_p);
      p2pSendPacket(&p2p_p);
      break;
    case TUNNEL_PARAM_CANFLY:
      setTunnelCanFly(p->data[1]);
  }
}

void p2pParametersHandler(P2PPacket *p) {
  setNDrones(p->rxdata[0]); // set nDrones for now only TODO
}

void tunnelParametersInit() {
    p2pRegisterPortCB(P2P_PORT_PARAM, p2pParametersHandler);
}

bool tunnelParametersTest() {
    return true;
}