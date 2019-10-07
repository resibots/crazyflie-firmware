/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_avoider.c - gets the multiranger + zranger distance values
 *                    and computes a repulsion force for avoiding obstacles.
 */

#include "tunnel_avoider.h"

#include "range.h"
#include "led.h"

#define LINSCALE(domain_low, domain_high, codomain_low, codomain_high, value) (((codomain_high - codomain_low) / (domain_high - domain_low)) * (value - domain_low) + codomain_low)

void tunnelAvoiderUpdate() {
  // TODO return the repulsion force somehow (+ 2D repulsion)

  float left  = rangeGet(rangeLeft);
  float right = rangeGet(rangeRight);

  // LEDs for some visual obstacle detection feedback
  if(left < 300) ledSet(LED_GREEN_R, true);
  else ledSet(LED_GREEN_R, false);
  if(right < 300) ledSet(LED_RED_R, true);
  else ledSet(LED_RED_R, false);
  
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
}

void tunnelAvoiderInit(void) {

}

bool tunnelAvoiderTest(void) {
    return true;
}