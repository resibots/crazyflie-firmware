/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_avoider.c - Gets the multiranger + zranger distance values
 *                    and computes a repulsion force for avoiding obstacles.
 * 
 * Is part of the navigation stack (commander, avoider & behavior).
 */

#include "tunnel_avoider.h"
#include "tunnel_config.h"
#include "tunnel_helpers.h"
#include "tunnel_behavior.h"
#include "tunnel_relay.h"
#include "tunnel_comm.h"
#include "tunnel.h"

#include "FreeRTOS.h"
#include "task.h"

#define DEBUG_MODULE "AVO"
#include "debug.h"

#include "range.h"
#include "led.h" 
#include "ledseq.h"

HorizontalRanges currentRanges;

HorizontalRanges *tunnelGetRanges() { return &currentRanges; }

static void updateRanges() {
  // Save distances in centimeters
  currentRanges.front = rangeGet(rangeFront) / 10;
  currentRanges.back  = rangeGet(rangeBack)  / 10;
  currentRanges.left  = rangeGet(rangeLeft)  / 10;
  currentRanges.right = rangeGet(rangeRight) / 10;
}

bool tunnelAvoiderCheckDeck() {
  if(currentRanges.left == 0 || currentRanges.right == 0 || currentRanges.front == 0 || currentRanges.back == 0) {
    ledseqRun(LED_RED_R, seq_warn);
    return false;
  } else ledseqStop(LED_RED_R, seq_warn);
  return true;
}

void tunnelAvoiderUpdate(TunnelHover *vel, bool enableCollisions) {
  updateRanges();

  // Quit now if collisions are disabled
  if(!enableCollisions || !tunnelAvoiderCheckDeck())
    return;

  // LEDs for some visual obstacle detection feedback
#ifdef TUNNEL_MULTIRANGER_LEDS
  if(left < 300) ledSet(LED_GREEN_R, true);
  else ledSet(LED_GREEN_R, false);
  if(right < 300) ledSet(LED_RED_R, true);
  else ledSet(LED_RED_R, false);
#endif

  // Main avoidance algorithm
#ifdef TUNNEL_QUAD_SHAPE_X
  // if(currentRanges.left > TUNNEL_RANGER_TRIGGER_DIST || currentRanges.right > TUNNEL_RANGER_TRIGGER_DIST || currentRanges.front < TUNNEL_RANGER_DANGER_DIST) {
  //   DEBUG_PRINT("Danger/n");
  //   tunnelSetBehavior(TUNNEL_BEHAVIOR_SCAN);
  //   return;
  // }

  // Avoid the obstacles with pushing forces
  #ifdef TUNNEL_AVOID_LEFTRIGHT
    if(currentRanges.left < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.left);
    if(currentRanges.right < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.right);
  #endif
  #ifdef TUNNEL_AVOID_FRONTBACK
    if(currentRanges.front < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.front);
    if(currentRanges.back < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.back);
  #endif

  // Turn based on the ranging distances, used to follow tunnel turns
  #ifdef TUNNEL_TURNING_ENABLE
    if(currentRanges.left < TUNNEL_RANGER_TRIGGER_DIST && currentRanges.right < TUNNEL_RANGER_TRIGGER_DIST)
      vel->yawrate = ((vel->vx > 0) ? 1.f : -1.f) * TUNNEL_RANGER_TURN_FORCE * (float)(currentRanges.left - currentRanges.right);
  #endif
#endif

#ifdef TUNNEL_QUAD_SHAPE_PLUS
  // Using left-right and front-back repulsion forces

  // #ifdef TUNNEL_AVOID_LEFTRIGHT // Using the mean of the 2 diagonal sensors for left-right avoiding
  //   if(currentRanges.left < TUNNEL_RANGER_TRIGGER_DIST && currentRanges.front < TUNNEL_RANGER_TRIGGER_DIST)
  //     vel->vy -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, (currentRanges.left + currentRanges.front) / 2.f);
  //   if(currentRanges.right < TUNNEL_RANGER_TRIGGER_DIST && currentRanges.back < TUNNEL_RANGER_TRIGGER_DIST)
  //     vel->vy += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, (currentRanges.right + currentRanges.back) / 2.f);
  // #endif
  #ifdef TUNNEL_AVOID_LEFTRIGHT // Using only the front diagonal sensors for left-right avoiding
    // Regular left-right avoidance
    if(currentRanges.front < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.front);
    if(currentRanges.right < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.right);
  #endif
  #ifdef TUNNEL_AVOID_FRONTBACK
    if(currentRanges.right < TUNNEL_RANGER_TRIGGER_DIST && currentRanges.front < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, (currentRanges.right + currentRanges.front) / 2.f);
    if(currentRanges.left < TUNNEL_RANGER_TRIGGER_DIST && currentRanges.back < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, (currentRanges.left + currentRanges.back) / 2.f);
  #endif

  #ifdef TUNNEL_TURNING_ENABLE
    if(currentRanges.right < TUNNEL_RANGER_TRIGGER_DIST && currentRanges.back < TUNNEL_RANGER_TRIGGER_DIST)
      vel->yawrate += TUNNEL_RANGER_TURN_FORCE * (currentRanges.right - currentRanges.back);
    if(currentRanges.left < TUNNEL_RANGER_TRIGGER_DIST && currentRanges.front < TUNNEL_RANGER_TRIGGER_DIST)
      vel->yawrate += TUNNEL_RANGER_TURN_FORCE * (currentRanges.left - currentRanges.front);
  #endif

  // Using independant repulsion forces for safety when coming too close of an obstacle
  float force_lr = 0, force_fb = 0;
  if(currentRanges.left < TUNNEL_RANGER_DANGER_DIST)
    force_lr = -TUNNEL_RANGER_AVOID_FORCE / 2;
  if(currentRanges.right < TUNNEL_RANGER_DANGER_DIST)
    force_lr =  TUNNEL_RANGER_AVOID_FORCE / 2;
  if(currentRanges.front < TUNNEL_RANGER_DANGER_DIST)
    force_fb = -TUNNEL_RANGER_AVOID_FORCE / 2;
  if(currentRanges.back < TUNNEL_RANGER_DANGER_DIST)
    force_fb =  TUNNEL_RANGER_AVOID_FORCE / 2;
  vel->vx += SQRT2_2 * (force_fb - force_lr);
  vel->vy += SQRT2_2 * (force_fb + force_lr);

  // Safety in case a laser looses track of a wall
  int lostWallsFlag = 0;
  if(currentRanges.front == 0 || currentRanges.front > TUNNEL_RANGER_TRIGGER_DIST) {
    vel->vx = 0;
    vel->vy = 0;
    vel->yawrate = TUNNEL_MAX_TURN_SPEED / 2;
    lostWallsFlag++;
  }
  if(currentRanges.right == 0 || currentRanges.right > TUNNEL_RANGER_TRIGGER_DIST) {
    vel->vx = 0;
    vel->vy = 0;
    vel->yawrate = -TUNNEL_MAX_TURN_SPEED / 2;
    lostWallsFlag++;
  }
  #ifdef TUNNEL_STOP_ON_WALLS_LOST
    if(lostWallsFlag == 2)
      tunnelSetDroneState(DRONE_STATE_CRASHED);
  #endif
#endif
}

void tunnelAvoiderInit(void) {
  currentRanges.front = 0;
  currentRanges.back  = 0;
  currentRanges.left  = 0;
  currentRanges.right = 0;
}

bool tunnelAvoiderTest(void) {
    return true;
}