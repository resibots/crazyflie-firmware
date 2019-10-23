/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_avoider.c - gets the multiranger + zranger distance values
 *                    and computes a repulsion force for avoiding obstacles.
 * 
 * Is part of the navigation stack (commander, avoider & behavior).
 */

#include "tunnel_avoider.h"
#include "tunnel_config.h"
#include "tunnel_helpers.h"

#include "range.h"
#include "led.h" 
#include "ledseq.h"

// Special avoiding behaviors

void tunnelBehaviorAvoiderUpdate(TunnelHover *vel) {

}

// Regular avoiding

bool tunnelAvoiderCheckDeck() {
  if(rangeGet(rangeLeft) == 0 || rangeGet(rangeRight) == 0 || rangeGet(rangeFront) == 0 || rangeGet(rangeBack) == 0) {
    ledseqRun(LED_RED_R, seq_warn);
    return false;
  } else ledseqStop(LED_RED_R, seq_warn);
  return true;
}

void tunnelAvoiderUpdate(TunnelHover *vel) {
  float left  = rangeGet(rangeLeft), right = rangeGet(rangeRight), front = rangeGet(rangeFront), back = rangeGet(rangeBack);

  // LEDs for some visual obstacle detection feedback
#ifdef TUNNEL_MULTIRANGER_LEDS
  if(left < 300) ledSet(LED_GREEN_R, true);
  else ledSet(LED_GREEN_R, false);
  if(right < 300) ledSet(LED_RED_R, true);
  else ledSet(LED_RED_R, false);
#endif

#ifdef TUNNEL_QUAD_SHAPE_X
  // Avoid the obstacles with pushing forces
  #ifdef TUNNEL_AVOID_LEFTRIGHT
    if(left < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, left);
    if(right < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, right);
  #endif
  #ifdef TUNNEL_AVOID_FRONTBACK
    if(front < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, front);
    if(back < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, back);
  #endif

  // Turn based on the ranging distances, used to follow tunnel turns
  #ifdef TUNNEL_TURNING_ENABLE
    if(left < TUNNEL_RANGER_TRIGGER_DIST && right < TUNNEL_RANGER_TRIGGER_DIST)
      vel->yawrate = ((vel->vx > 0) ? 1.f : -1.f) * TUNNEL_RANGER_TURN_FORCE * (float)(left - right);
  #endif
#endif

#ifdef TUNNEL_QUAD_SHAPE_PLUS
  /* Using independant repulsion forces, not used anymore
  float force_lr = 0, force_fb = 0;
  if(left < TUNNEL_RANGER_TRIGGER_DIST)
    force_lr -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, left);
  if(right < TUNNEL_RANGER_TRIGGER_DIST)
    force_lr += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, right);
  if(front < TUNNEL_RANGER_TRIGGER_DIST)
    force_fb -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, front);
  if(back < TUNNEL_RANGER_TRIGGER_DIST)
    force_fb += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, back);
  vel->vx += SQRT2_2 * (force_fb - force_lr);
  vel->vy += SQRT2_2 * (force_fb + force_lr);*/

  #ifdef TUNNEL_AVOID_LEFTRIGHT
    if(left < TUNNEL_RANGER_TRIGGER_DIST && front < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, (left + front) / 2.f);
    if(right < TUNNEL_RANGER_TRIGGER_DIST && back < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, (right + back) / 2.f);
  #endif
  #ifdef TUNNEL_AVOID_FRONTBACK
    if(right < TUNNEL_RANGER_TRIGGER_DIST && front < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, (right + front) / 2.f);
    if(left < TUNNEL_RANGER_TRIGGER_DIST && back < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, (left + back) / 2.f);
  #endif

  #ifdef TUNNEL_TURNING_ENABLE
    if(right < TUNNEL_RANGER_TRIGGER_DIST && back < TUNNEL_RANGER_TRIGGER_DIST)
      vel->yawrate += TUNNEL_RANGER_TURN_FORCE * (right - back);
    if(left < TUNNEL_RANGER_TRIGGER_DIST && front < TUNNEL_RANGER_TRIGGER_DIST)
      vel->yawrate += TUNNEL_RANGER_TURN_FORCE * (left - front);
  #endif
#endif
}

void tunnelAvoiderInit(void) {

}

bool tunnelAvoiderTest(void) {
    return true;
}