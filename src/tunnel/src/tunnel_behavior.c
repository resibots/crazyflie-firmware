/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_behavior.c - Submodule that applies the correct movement policy 
 *                     and manages behavior changes. Returns the desired movement.
 * 
 * Is part of the navigation stack (commander, avoider & behavior).
 */

#include "tunnel_behavior.h"
#include "tunnel_config.h"
#include "tunnel_commander.h"
#include "tunnel_signal.h"
#include "tunnel_avoider.h"
#include "tunnel.h"

#include "behavior_types.h"

#define DEBUG_MODULE "BEH"
#include "debug.h"

#include "FreeRTOS.h"
#include "task.h"

static TunnelBehavior currentBehavior;
static TunnelBehavior previousBehavior;

static BehaviorType *behaviors[] = {
  [TUNNEL_BEHAVIOR_IDLE]        = &behavior_idle,
  [TUNNEL_BEHAVIOR_TAKE_OFF]    = &behavior_takeoff,
  [TUNNEL_BEHAVIOR_HOVER]       = &behavior_hover,
  [TUNNEL_BEHAVIOR_GOTO]        = &behavior_goto,
  [TUNNEL_BEHAVIOR_POSITIONING] = &behavior_positioning,
  [TUNNEL_BEHAVIOR_RECONNECT]   = &behavior_reconnect,
  [TUNNEL_BEHAVIOR_ROLLBACK]    = &behavior_rollback,
  [TUNNEL_BEHAVIOR_SCAN]        = &behavior_scan,
  [TUNNEL_BEHAVIOR_LAND]        = &behavior_land,
};

static uint32_t takeOffTime = 0;

// Main update function
void tunnelBehaviorUpdate(TunnelSetpoint *vel, bool *enableCollisions) {
  behaviors[currentBehavior]->update(vel, enableCollisions);
}

// Current behavior management

TunnelBehavior tunnelGetCurrentBehavior() {
  return currentBehavior;
}

static void setBehavior(TunnelBehavior newBehavior) {
  if(newBehavior != currentBehavior) {
    // DEBUG_PRINT("%i->%i\n", currentBehavior, newBehavior);
    currentBehavior = newBehavior;
    behaviors[currentBehavior]->init();
  }
}

void tunnelSetBehavior(TunnelBehavior newBehavior) {
  if(newBehavior != currentBehavior) {
    previousBehavior = currentBehavior;
    setBehavior(newBehavior);
  }
}

void tunnelSetPreviousBehavior() {
  setBehavior(previousBehavior);
}

uint32_t tunnelGetTakeOffTime() { return takeOffTime; }
void tunnelMarkTakeOffTime() { takeOffTime = xTaskGetTickCount(); }

// Submodule initialization

void tunnelBehaviorInit() {
  tunnelSetBehavior(TUNNEL_BEHAVIOR_IDLE);
}

bool tunnelBehaviorTest() {
  return true;
}