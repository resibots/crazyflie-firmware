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

#include "range.h"
#include "led.h"

#define LINSCALE(domain_low, domain_high, codomain_low, codomain_high, value) (((codomain_high - codomain_low) / (domain_high - domain_low)) * (value - domain_low) + codomain_low)

void tunnelAvoiderUpdate(TunnelHover *vel) {
#ifdef TUNNEL_MULTIRANGER_LEDS
  // LEDs for some visual obstacle detection feedback
  if(rangeGet(rangeLeft) < 300) ledSet(LED_GREEN_R, true);
  else ledSet(LED_GREEN_R, false);
  if(rangeGet(rangeRight) < 300) ledSet(LED_RED_R, true);
  else ledSet(LED_RED_R, false);
#endif

  // Avoid the obstacles with pushing forces
#ifdef TUNNEL_AVOID_LEFTRIGHT
  if(rangeGet(rangeLeft) < TUNNEL_RANGER_TRIGGER_DIST) 
    vel->vy -= TUNNEL_RANGER_AVOID_FORCE * rangeGet(rangeLeft)  / 1000;
  if(rangeGet(rangeRight) < TUNNEL_RANGER_TRIGGER_DIST)
    vel->vy += TUNNEL_RANGER_AVOID_FORCE * rangeGet(rangeRight) / 1000;
#endif
#ifdef TUNNEL_AVOID_FRONTBACK
  if(rangeGet(rangeFront) < TUNNEL_RANGER_TRIGGER_DIST)
    vel->vx -= TUNNEL_RANGER_AVOID_FORCE * rangeGet(rangeFront) / 1000;
  if(rangeGet(rangeBack) < TUNNEL_RANGER_TRIGGER_DIST)
    vel->vx += TUNNEL_RANGER_AVOID_FORCE * rangeGet(rangeBack)  / 1000;
#endif
#ifdef TUNNEL_AVOID_UPDOWN
  //TODO up down avoiding
#endif
}

void tunnelAvoiderInit(void) {

}

bool tunnelAvoiderTest(void) {
    return true;
}

/* Old method
// If there are two walls on each side, center the drone
float repulsion = 0;
if(left < 2000 && right < 2000) {
  float diff = left - right;
  if(diff < 0) diff *= -1;
  float sign = (left - right > 0) ? 1.f : -1.f;

  if(diff > 500) 
    repulsion = sign * 0.5f;
  else 
    repulsion = sign * LINSCALE(0.f, 500.f, 0.1f, 0.5f, diff);
}
*/