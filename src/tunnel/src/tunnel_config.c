/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_config.c - Common interface for all source files for setting
 *                   and getting general parameters about the drone and chain.
 *
 * The header file also contains all compile-time settings and configuration.
 */

#include "tunnel.h"
#include "tunnel_config.h"
#include "tunnel_behavior.h"
#include "tunnel_commander.h"

#include "configblock.h"

#define DEBUG_MODULE "CFG"
#include "debug.h"

// Follower and leader IDs getters and setters
// Note: the drone has no follower or leader if the value is getDroneID()
struct {
  uint8_t followerID : 4;
  uint8_t leaderID   : 4;
} chainPeers;

bool isPeerIDValid(uint8_t id) { return id != getDroneId(); }

uint8_t getFollowerID() { return chainPeers.followerID; }
void setFollowerID(uint8_t newID) { chainPeers.followerID = newID; }

uint8_t getLeaderID() { return chainPeers.leaderID; }
void setLeaderID(uint8_t newID) { chainPeers.leaderID = newID; }

void tunnelAutoSetFollowerLeader() {
  // Normal follower & leader IDs
  if(getDroneId() > 0)
    setLeaderID(getDroneId() - 1);
  if(getDroneId() < getNDrones() - 1)
    setFollowerID(getDroneId() + 1);

  // Exceptions
  if(getDroneId() == 0)
    setLeaderID(getDroneId());
  if(getDroneId() == getNDrones() - 1)
    setFollowerID(getDroneId());
  if(getDroneId() >= getNDrones()) {
    setLeaderID(getDroneId());
    setFollowerID(getDroneId());
  }
}

void tunnelAutoSetIdleInactive() {
  if(getDroneId() >= getNDrones())
    tunnelSetDroneState(DRONE_STATE_INACTIVE);
  else if(tunnelGetDroneState() == DRONE_STATE_INACTIVE)
    tunnelSetDroneState(DRONE_STATE_IDLE);
}

// Keep track of the drone that is currently connected to the base
// Should be automatically changed when the true drone notifies itself
static uint8_t baseDroneID = DEFAULT_N_DRONES - 1;
void setBaseDroneID(uint8_t id) { baseDroneID = id & 0x0F; }
uint8_t getBaseDroneID() { return baseDroneID; }

// Number of available drones in the tunnel exploration crew
static uint8_t nDrones = DEFAULT_N_DRONES; // 15 max because of the 4-bit addresses

uint8_t getNDrones() { return nDrones; }
void setNDrones(uint8_t ndrones) {
  nDrones = ndrones;
  tunnelAutoSetFollowerLeader();
  tunnelAutoSetIdleInactive();
}

// Set by the operator. The Tunnel module uses the motors only if this is set to true.
static bool tunnelCanFly;

uint8_t getTunnelCanFly() { return tunnelCanFly; }

void setTunnelCanFlySoft(bool canfly) {
  if(canfly != tunnelCanFly) {
    if(!canfly) {
      if(tunnelGetCurrentBehavior() != TUNNEL_BEHAVIOR_IDLE)
        tunnelSetBehavior(TUNNEL_BEHAVIOR_LAND);
      else {
        tunnelCanFly = false;
        sendSetpointStop();
      }
    }
    else tunnelCanFly = true;
  }
}

// Set canfly without processing
void setTunnelCanFly(bool canfly) { tunnelCanFly = canfly; }

// Keep track of how long we have been flying since the last take off
uint32_t getTunnelFlightTime() { return xTaskGetTickCount() - tunnelGetTakeOffTime(); }

uint8_t getDroneId() {
  return (uint8_t)configblockGetRadioAddress() & 0x0F;
}