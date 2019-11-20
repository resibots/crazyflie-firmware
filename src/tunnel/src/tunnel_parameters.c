/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_param.c - Submodule for setting tunnel exploration
 *                  related parameters (e.g. number of drones in the chain)
 */

#include "tunnel_parameters.h"
#include "tunnel_config.h"
#include "tunnel_relay.h"
#include "tunnel.h"

#include "p2p.h"
#include "led.h"

#define BROADCAST_N_TRIES 5

typedef enum {
  TUNNEL_PARAM_NDRONES = 0x00,
  TUNNEL_PARAM_MODE    = 0x01,
} TunnelParameter;

static void tunnelProcessParamPacket(uint8_t *data, bool broadcast) {
  static P2PPacket p_broadcast;

  switch(data[0]) {
    case TUNNEL_PARAM_NDRONES: {
      setNDrones(data[1]);

      if(broadcast) {
        // Broadcast the new number of drones to the other drones
        for(int i = 0; i < BROADCAST_N_TRIES; i++) {
          p_broadcast.port   = P2P_PORT_PARAM;
          p_broadcast.txdata[0] = TUNNEL_PARAM_NDRONES;
          p_broadcast.txdata[1] = getNDrones();
          p_broadcast.size = 2;
          tunnelTraceP2PPacket(&p_broadcast, TRACE_MODE_ALL);
        }
      }
      break;
    }
    case TUNNEL_PARAM_MODE: {
      DroneMode mode = (data[1] == DRONE_MODE_AUTO) ? DRONE_MODE_AUTO : DRONE_MODE_MANUAL;
      tunnelSetDroneMode(mode);

      if(broadcast) {
        // Broadcast the new mode to all drones
        for(int i = 0; i < BROADCAST_N_TRIES; i++) {
          p_broadcast.port   = P2P_PORT_PARAM;
          p_broadcast.txdata[0] = TUNNEL_PARAM_MODE;
          p_broadcast.txdata[1] = mode;
          p_broadcast.size = 2;
          tunnelTraceP2PPacket(&p_broadcast, TRACE_MODE_ALL);
        }
      }
      break;
    }
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