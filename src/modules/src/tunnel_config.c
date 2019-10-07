/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_config.c - Manages general chain parameters
 */

#include "tunnel_config.h"

#include "configblock.h"

// Number of available drones in the tunnel exploration crew
static uint8_t nDrones = 3; // 15 max because of the 4-bit addresses

uint8_t getNDrones() { return nDrones; }
void setNDrones(uint8_t ndrones) { nDrones = ndrones; }

// Set by the operator. The Tunnel module uses the motors only if this is set to true.
static bool tunnelCanFly;

uint8_t getTunnelCanFly() { return tunnelCanFly; }
void setTunnelCanFly(uint8_t canfly) { tunnelCanFly = canfly; }

uint8_t getDroneId() {
  return (uint8_t)configblockGetRadioAddress() & 0x0F;
}