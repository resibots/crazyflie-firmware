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
#include "tunnel_behavior.h"
#include "tunnel_relay.h"

#include "FreeRTOS.h"
#include "task.h"

#define DEBUG_MODULE "AVO"
#include "debug.h"

#include "range.h"
#include "led.h" 
#include "ledseq.h"

#include <stdlib.h>

typedef struct {
  uint8_t front;
  uint8_t back;
  uint8_t left;
  uint8_t right;
} HorizontalRanges; // centimeters
HorizontalRanges currentRanges;

// Special avoiding behaviors

#define INACTIVE_TIME  500 // time for centering in the tunnel before starting the scan
#define ROTATION_SPEED  20 // deg per sec
#define SCAN_RESOLUTION 12 // Logging resolution in degrees, 12 because it barely fits in a CRTP packet
#define N_MEASURES (4 * (90 / SCAN_RESOLUTION))

static uint8_t measuresBuffer[N_MEASURES];
static float prevAngle, currentAngle, goalAngle;
static uint32_t prevUpdateTime = 0;

enum {
  BEHAVIOR_SCAN_STATE_INACTIVE, // No movement, enable collisions for a while to center in the tunnel
  BEHAVIOR_SCAN_STATE_INIT,     // Resetting variables
  BEHAVIOR_SCAN_STATE_MEASURE,  // Rotating and logging values. Decides on transition to GOTO
  BEHAVIOR_SCAN_STATE_GOTO,     // Rotating to the estimated tunnel direction
} scanBehaviorState = BEHAVIOR_SCAN_STATE_INACTIVE;

static void sendScan() {
  CRTPTunnelPacket p_scan;
  p_scan.port = CRTP_PORT_TUNNEL;
  p_scan.channel = 0x01;//TODO clean
  memcpy(p_scan.basedata, measuresBuffer, N_MEASURES);
  p_scan.size = N_MEASURES;
  tunnelSendCRTPPacketToBase(&p_scan);
}

static void saveRangesToBuffer(float frontAngle) {
  // Index out of bounds protection
  if((int)frontAngle > 90)
    return;

  uint16_t frontIndex = (int)frontAngle / SCAN_RESOLUTION;
  measuresBuffer[frontIndex]                              = currentRanges.front;
  measuresBuffer[frontIndex +     (90 / SCAN_RESOLUTION)] = currentRanges.right;
  measuresBuffer[frontIndex + 2 * (90 / SCAN_RESOLUTION)] = currentRanges.back;
  if(frontIndex + 3 * (90 / SCAN_RESOLUTION) < N_MEASURES)
    measuresBuffer[frontIndex + 3 * (90 / SCAN_RESOLUTION)] = currentRanges.left;

  DEBUG_PRINT("Logging i=%i a=%i\n", (int)frontAngle / SCAN_RESOLUTION, (int)frontAngle);
}

void tunnelBehaviorScanEnable() {
  DEBUG_PRINT("Starting scan, %i points...\n", N_MEASURES);
  scanBehaviorState = BEHAVIOR_SCAN_STATE_INACTIVE;
  prevAngle = currentAngle = goalAngle = 0;
  prevUpdateTime = xTaskGetTickCount(); // used for staying inactive for a while
}

void tunnelBehaviorScanUpdate(TunnelHover *vel, bool *enableCollisions) {
  // Don't move on other axis
  vel->vx = 0;
  vel->vy = 0;
  vel->zDistance = TUNNEL_DEFAULT_HEIGHT;

  // Disable avoider while scanning 
  *enableCollisions = false;

  // Turn around and log the distances
  switch (scanBehaviorState) {
    case BEHAVIOR_SCAN_STATE_INACTIVE:
      vel->yawrate   = 0;
      *enableCollisions = true;
      if(xTaskGetTickCount() - prevUpdateTime > INACTIVE_TIME)
        scanBehaviorState = BEHAVIOR_SCAN_STATE_INIT;
      break;
    case BEHAVIOR_SCAN_STATE_INIT:
      vel->yawrate = 0;
      currentAngle = 0;
      prevUpdateTime = xTaskGetTickCount();
      scanBehaviorState = BEHAVIOR_SCAN_STATE_MEASURE;
      saveRangesToBuffer(currentAngle);
      break;
    case BEHAVIOR_SCAN_STATE_MEASURE:
      vel->yawrate = ROTATION_SPEED;
      currentAngle += vel->yawrate * (float)(xTaskGetTickCount() - prevUpdateTime) / 1000.f;

      // Log measurements
      if(prevAngle < currentAngle - (int)currentAngle % SCAN_RESOLUTION - (currentAngle - (int)currentAngle))
        saveRangesToBuffer(currentAngle);

      prevUpdateTime = xTaskGetTickCount();
      if(currentAngle > 90) {
        vel->yawrate = 0;

        // Choose best angle
        uint8_t best_i = 0, best = 2 * TUNNEL_RANGER_TRIGGER_DIST;
        for(int i = 0; i < N_MEASURES / 2; i++) {
          if(measuresBuffer[i]                              > 0 && measuresBuffer[i]                              < TUNNEL_RANGER_TRIGGER_DIST &&
             measuresBuffer[i + 2 * (90 / SCAN_RESOLUTION)] > 0 && measuresBuffer[i + 2 * (90 / SCAN_RESOLUTION)] < TUNNEL_RANGER_TRIGGER_DIST) {
            uint8_t dist = measuresBuffer[i] + measuresBuffer[i + 2 * (90 / SCAN_RESOLUTION)];
            if(dist < best) {
              best_i = i;
              best = dist;
              DEBUG_PRINT("New best i=%i d=%i\n", best_i, best);
            }
          }
        }
        // goalAngle = best_i * SCAN_RESOLUTION; //TODO verify + choose 180 orientation
        goalAngle = 0;

        scanBehaviorState = BEHAVIOR_SCAN_STATE_GOTO;
        DEBUG_PRINT("Going to chosen i=%i a=%i...\n", best_i, (int)goalAngle);
        sendScan();
      }
      break;
    case BEHAVIOR_SCAN_STATE_GOTO:
      vel->yawrate = ((goalAngle - currentAngle > 0) ? 1 : -1) * ROTATION_SPEED * 2;
      currentAngle += vel->yawrate * (float)(xTaskGetTickCount() - prevUpdateTime) / 1000.f;

      prevUpdateTime = xTaskGetTickCount();
      if(abs(goalAngle - currentAngle) < 2) {
        DEBUG_PRINT("Finished scan!\n");
        tunnelSetPreviousBehavior();
      }
      break;
  }

  prevAngle = currentAngle;
}

// Regular avoiding

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
  if(currentRanges.left > TUNNEL_RANGER_TRIGGER_DIST || currentRanges.right > TUNNEL_RANGER_TRIGGER_DIST || currentRanges.front < TUNNEL_RANGER_DANGER_DIST) {
    tunnelSetBehavior(TUNNEL_BEHAVIOR_SCAN);
    return;
  }

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
  // Using independant repulsion forces, not used anymore

  // float force_lr = 0, force_fb = 0;
  // if(currentRanges.left < TUNNEL_RANGER_TRIGGER_DIST)
  //   force_lr -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.left);
  // if(currentRanges.right < TUNNEL_RANGER_TRIGGER_DIST)
  //   force_lr += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.right);
  // if(currentRanges.front < TUNNEL_RANGER_TRIGGER_DIST)
  //   force_fb -= LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.front);
  // if(currentRanges.back < TUNNEL_RANGER_TRIGGER_DIST)
  //   force_fb += LINSCALE(0.f, TUNNEL_RANGER_TRIGGER_DIST, TUNNEL_RANGER_AVOID_FORCE, 0.f, currentRanges.back);
  // vel->vx += SQRT2_2 * (force_fb - force_lr);
  // vel->vy += SQRT2_2 * (force_fb + force_lr);

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
    // Safety to make sure not to touch obstacles
    if(currentRanges.left < TUNNEL_RANGER_DANGER_DIST)
      vel->vy = -TUNNEL_RANGER_AVOID_FORCE / 2;
    if(currentRanges.back < TUNNEL_RANGER_DANGER_DIST)
      vel->vy =  TUNNEL_RANGER_AVOID_FORCE / 2;
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
  if(lostWallsFlag == 2)
    setTunnelCanFly(false);
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