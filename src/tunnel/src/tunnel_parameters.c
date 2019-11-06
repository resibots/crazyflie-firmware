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

static void tunnelProcessParamPacket(uint8_t *data, bool broadcast) {
  switch(data[0]) {
    case TUNNEL_PARAM_NDRONES:
      setNDrones(data[1]);

      if(broadcast) {
        // Broadcast the new number of drones to the other drones
        P2PPacket p2p_p;
        p2p_p.txdest = 0x0F; // broadcast
        p2p_p.port   = P2P_PORT_PARAM;
        p2p_p.txdata[0] = TUNNEL_PARAM_NDRONES;
        p2p_p.txdata[1] = getNDrones();
        p2p_p.size = 2;
        p2pSendPacket(&p2p_p);
        p2pSendPacket(&p2p_p);
        p2pSendPacket(&p2p_p);
      }
      break;
    case TUNNEL_PARAM_CANFLY:
      setTunnelCanFly(data[1]);

      if(broadcast) {
        // Broadcast the new state to the other drones
        P2PPacket p2p_p;
        p2p_p.txdest = 0x0F; // broadcast
        p2p_p.port   = P2P_PORT_PARAM;
        p2p_p.txdata[0] = TUNNEL_PARAM_CANFLY;
        p2p_p.txdata[1] = (uint8_t)getTunnelCanFly();
        p2p_p.size = 2;
        p2pSendPacket(&p2p_p);
        p2pSendPacket(&p2p_p);
        p2pSendPacket(&p2p_p);
      }
      break;
  }
}

void crtpTunnelParametersHandler(CRTPTunnelPacket *p) {
  // Set the parameter and tell the other drones too
  tunnelProcessParamPacket(p->dronedata, true);
}

void p2pParametersHandler(P2PPacket *p) {
  // Set the parameter only
  tunnelProcessParamPacket(p->rxdata, false);
}

void tunnelParametersInit() {
    p2pRegisterPortCB(P2P_PORT_PARAM, p2pParametersHandler);
}

bool tunnelParametersTest() {
    return true;
}