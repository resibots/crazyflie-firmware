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

void tunnelAvoiderUpdate(TunnelHover *vel) {
  // LEDs for some visual obstacle detection feedback
#ifdef TUNNEL_MULTIRANGER_LEDS
  if(rangeGet(rangeLeft) < 300) ledSet(LED_GREEN_R, true);
  else ledSet(LED_GREEN_R, false);
  if(rangeGet(rangeRight) < 300) ledSet(LED_RED_R, true);
  else ledSet(LED_RED_R, false);
#endif

#ifdef TUNNEL_QUAD_SHAPE_X
  // Avoid the obstacles with pushing forces
  #ifdef TUNNEL_AVOID_LEFTRIGHT
    if(rangeGet(rangeLeft) < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, rangeGet(rangeLeft));
    if(rangeGet(rangeRight) < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vy += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, rangeGet(rangeRight));
  #endif
  #ifdef TUNNEL_AVOID_FRONTBACK
    if(rangeGet(rangeFront) < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, rangeGet(rangeFront));
    if(rangeGet(rangeBack) < TUNNEL_RANGER_TRIGGER_DIST)
      vel->vx += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, rangeGet(rangeBack));
  #endif

  // Turn based on the ranging distances, used to follow tunnel turns
  #ifdef TUNNEL_TURNING_ENABLE
    if(rangeGet(rangeLeft) < TUNNEL_RANGER_TRIGGER_DIST && rangeGet(rangeRight) < TUNNEL_RANGER_TRIGGER_DIST)
      vel->yawrate = ((vel->vx > 0) ? 1.f : -1.f) * TUNNEL_RANGER_TURN_FORCE * (float)(rangeGet(rangeLeft) - rangeGet(rangeRight));
  #endif
#endif

#ifdef TUNNEL_QUAD_SHAPE_PLUS
  float force_lr = 0, force_fb = 0;
  if(rangeGet(rangeLeft) < TUNNEL_RANGER_TRIGGER_DIST)
    force_lr -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, rangeGet(rangeLeft));
  if(rangeGet(rangeRight) < TUNNEL_RANGER_TRIGGER_DIST)
    force_lr += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, rangeGet(rangeRight));
  if(rangeGet(rangeFront) < TUNNEL_RANGER_TRIGGER_DIST)
    force_fb -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, rangeGet(rangeFront));
  if(rangeGet(rangeBack) < TUNNEL_RANGER_TRIGGER_DIST)
    force_fb += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, rangeGet(rangeBack));
  vel->vx += SQRT2_2 * (force_fb - force_lr);
  vel->vy += SQRT2_2 * (force_fb + force_lr);

  #ifdef TUNNEL_TURNING_ENABLE
    if(rangeGet(rangeRight) < TUNNEL_RANGER_TRIGGER_DIST && rangeGet(rangeBack) < TUNNEL_RANGER_TRIGGER_DIST)
      vel->yawrate += TUNNEL_RANGER_TURN_FORCE * (float)(rangeGet(rangeRight) - rangeGet(rangeBack));
    if(rangeGet(rangeLeft) < TUNNEL_RANGER_TRIGGER_DIST && rangeGet(rangeFront) < TUNNEL_RANGER_TRIGGER_DIST)
      vel->yawrate += TUNNEL_RANGER_TURN_FORCE * (float)(rangeGet(rangeLeft) - rangeGet(rangeFront));
  #endif
#endif
}

void tunnelAvoiderInit(void) {

}

bool tunnelAvoiderTest(void) {
    return true;
}