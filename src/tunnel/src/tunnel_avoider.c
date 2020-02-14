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
#include "tunnel.h"
#include "range.h"

#define DEBUG_MODULE "AVOID"
#include "debug.h"
#include <stdlib.h>
#include <math.h>

//TODO only made for plus shape

#define RANGE_VALID(range) ((range) > 0 && (range) < TUNNEL_RANGER_TRIGGER_DIST)

HorizontalRanges currentRanges;
HorizontalRanges *tunnelGetRanges() { return &currentRanges; }

typedef enum {
  DIRECTION_FRONT = 0,
  DIRECTION_RIGHT,
  DIRECTION_BACK,
  DIRECTION_LEFT,
  _DIRECTION_NONE
} LaserDirection;
LaserDirection currentWall;

typedef struct {
  uint8_t *laser1;
  uint8_t *laser2;
  float diff;
  float ratio;
  float center;
} LaserCouple;
LaserCouple sideCouples[_DIRECTION_NONE];

bool tunnelAvoiderCheckDeck() {
  return (currentRanges.left != 0 && currentRanges.right != 0 && currentRanges.front != 0 && currentRanges.back != 0);
}

static void updateRanges() {
  // Save distances in centimeters
  currentRanges.front = rangeGet(rangeFront) / 10;
  currentRanges.back  = rangeGet(rangeBack)  / 10;
  currentRanges.left  = rangeGet(rangeLeft)  / 10;
  currentRanges.right = rangeGet(rangeRight) / 10;

  // Update couples ratios
  for(int i = 0; i < _DIRECTION_NONE; i++) {
    float dist1 = *sideCouples[i].laser1;
    float dist2 = *sideCouples[i].laser2;
    sideCouples[i].diff = dist1 - dist2;
    sideCouples[i].center = sqrtf(dist1 * dist2 * (1 - (dist1*dist1 + dist2*dist2) / powf(dist1 + dist2, 2.f)));
    sideCouples[i].ratio = (sideCouples[i].diff) / ((dist1 + dist2) / 2.f);
    if(sideCouples[i].ratio < 0) sideCouples[i].ratio *= -1.f;
  }
}

static inline bool isCoupleValid(LaserCouple *couple) {
  return (RANGE_VALID(*(couple->laser1)) && RANGE_VALID(*(couple->laser2)));
}

static void avoidCollisions(TunnelSetpoint *vel) {
  float force_lr = 0, force_fb = 0;
  if(currentRanges.left < TUNNEL_RANGER_DANGER_DIST)
    force_lr += -TUNNEL_MAX_SPEED / 2.f;
  if(currentRanges.right < TUNNEL_RANGER_DANGER_DIST)
    force_lr +=  TUNNEL_MAX_SPEED / 2.f;
  if(currentRanges.front < TUNNEL_RANGER_DANGER_DIST)
    force_fb += -TUNNEL_MAX_SPEED / 2.f;
  if(currentRanges.back < TUNNEL_RANGER_DANGER_DIST)
    force_fb +=  TUNNEL_MAX_SPEED / 2.f;

  if(force_lr != 0 || force_fb != 0) {
    vel->vx = SQRT2_2 * (force_fb - force_lr);
    vel->vy = SQRT2_2 * (force_fb + force_lr);
  }
}

void tunnelAvoiderUpdate(TunnelSetpoint *vel, bool enableCollisions) {
  // Read the multiranger ranges in our own structure (takes less calculations)
  updateRanges();

  // Quit now if collisions are disabled by the current behavior
  if(!enableCollisions)
    return;

  // Choose the wall side to use
  if(isCoupleValid(&sideCouples[DIRECTION_LEFT]) && isCoupleValid(&sideCouples[DIRECTION_RIGHT])) {
    float ratioDiff = sideCouples[DIRECTION_LEFT].ratio - sideCouples[DIRECTION_RIGHT].ratio;
    if(ratioDiff < 0) ratioDiff *= -1.f;

    // Take the closest wall in normal situations, but take the most normal ratio side possible if ratio difference is abnormal
    if(ratioDiff >= TUNNEL_RANGE_RATIO_MAX_DIFF)
      currentWall = (sideCouples[DIRECTION_LEFT].ratio <= sideCouples[DIRECTION_RIGHT].ratio) ? DIRECTION_LEFT : DIRECTION_RIGHT;
    else
      currentWall = (sideCouples[DIRECTION_LEFT].center <= sideCouples[DIRECTION_RIGHT].center) ? DIRECTION_LEFT : DIRECTION_RIGHT;
  }
  else if(!isCoupleValid(&sideCouples[DIRECTION_LEFT]))
    currentWall = DIRECTION_RIGHT;
  else if(!isCoupleValid(&sideCouples[DIRECTION_RIGHT]))
    currentWall = DIRECTION_LEFT;
  else // Don't follow any wall if no side seems to track any
    currentWall = _DIRECTION_NONE; 

  // Follow the current wall if there's 
  if(currentWall != _DIRECTION_NONE) {
    LaserDirection oppositeWall = (currentWall == DIRECTION_LEFT) ? DIRECTION_RIGHT : DIRECTION_LEFT;

    // Calculate rotation with the current wall
    float sign = (sideCouples[currentWall].diff >= 0) ? 1.f : -1.f;
    vel->yawrate += sign * TUNNEL_RANGER_TURN_FORCE * sideCouples[currentWall].ratio;

    // Choose at which distance to stay from the wall. If we see two walls center between them, else 
    // use the default distance.
    float mainDist = sideCouples[currentWall].center;
    float oppositeDist = sideCouples[oppositeWall].center;
    float goalDist = TUNNEL_DEFAULT_WALL_DIST;
    if(isCoupleValid(&sideCouples[oppositeWall]) && (mainDist + oppositeDist) <= TUNNEL_MAX_WIDTH)
      goalDist = (mainDist + oppositeDist) / 2.f;

    // Calculate translation (if there's a wall on the other side center based on
    // the min value of the sides, else go to a default distance to the current wall)
    sign = (currentWall == DIRECTION_RIGHT) ? 1.f : -1.f;
    vel->vy = sign * (TUNNEL_RANGER_AVOID_FORCE / 10.f) * (goalDist - mainDist);
  }

  // Use independant repulsion forces for safety when coming too close of an obstacle
  avoidCollisions(vel);
}

void tunnelAvoiderInit(void) {
  currentRanges.front = 0;
  currentRanges.back  = 0;
  currentRanges.left  = 0;
  currentRanges.right = 0;

  currentWall = DIRECTION_LEFT;
  sideCouples[DIRECTION_FRONT].laser1 = sideCouples[DIRECTION_LEFT ].laser2 = &currentRanges.front;
  sideCouples[DIRECTION_RIGHT].laser1 = sideCouples[DIRECTION_FRONT].laser2 = &currentRanges.right;
  sideCouples[DIRECTION_BACK ].laser1 = sideCouples[DIRECTION_RIGHT].laser2 = &currentRanges.back;
  sideCouples[DIRECTION_LEFT ].laser1 = sideCouples[DIRECTION_BACK ].laser2 = &currentRanges.left;
}

bool tunnelAvoiderTest(void) {
  return true;
}