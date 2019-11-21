#include "behavior_scan.h"
#include "tunnel_behavior.h"

#include "tunnel_config.h"
#include "tunnel_avoider.h"
#include "tunnel_comm.h"

#define DEBUG_MODULE "SCAN"
#include "debug.h"

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
  p_scan.channel = CRTP_TUNNEL_RESPONSE_CHANNEL_SCAN;
  memcpy(p_scan.basedata, measuresBuffer, N_MEASURES);
  p_scan.size = N_MEASURES;
  tunnelSendCRTPPacketToBase(&p_scan);
}

static void saveRangesToBuffer(float frontAngle) {
  // Index out of bounds protection
  if((int)frontAngle > 90)
    return;

  uint16_t frontIndex = (int)frontAngle / SCAN_RESOLUTION;
  measuresBuffer[frontIndex]                              = tunnelGetRanges()->front;
  measuresBuffer[frontIndex +     (90 / SCAN_RESOLUTION)] = tunnelGetRanges()->right;
  measuresBuffer[frontIndex + 2 * (90 / SCAN_RESOLUTION)] = tunnelGetRanges()->back;
  if(frontIndex + 3 * (90 / SCAN_RESOLUTION) < N_MEASURES)
    measuresBuffer[frontIndex + 3 * (90 / SCAN_RESOLUTION)] = tunnelGetRanges()->left;

  DEBUG_PRINT("Logging i=%i a=%i\n", (int)frontAngle / SCAN_RESOLUTION, (int)frontAngle);
}

void behaviorScanInit() {
  DEBUG_PRINT("Starting scan, %i points...\n", N_MEASURES);
  scanBehaviorState = BEHAVIOR_SCAN_STATE_INACTIVE;
  prevAngle = currentAngle = goalAngle = 0;
  prevUpdateTime = xTaskGetTickCount(); // used for staying inactive for a while
}

void behaviorScanUpdate(TunnelHover *vel, bool *enableCollisions) { //TODO transfer
  // Inactive axis
  vel->vx = 0;
  vel->vy = 0;
  vel->zDistance = TUNNEL_DEFAULT_HEIGHT;

  // Active axis: turn around and log the distances
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
        // uint8_t best_i = 0, best = 2 * TUNNEL_RANGER_TRIGGER_DIST;
        // for(int i = 0; i < N_MEASURES / 2; i++) {
        //   if(measuresBuffer[i]                              > 0 && measuresBuffer[i]                              < TUNNEL_RANGER_TRIGGER_DIST &&
        //      measuresBuffer[i + 2 * (90 / SCAN_RESOLUTION)] > 0 && measuresBuffer[i + 2 * (90 / SCAN_RESOLUTION)] < TUNNEL_RANGER_TRIGGER_DIST) {
        //     uint8_t dist = measuresBuffer[i] + measuresBuffer[i + 2 * (90 / SCAN_RESOLUTION)];
        //     if(dist < best) {
        //       best_i = i;
        //       best = dist;
        //       DEBUG_PRINT("New best i=%i d=%i\n", best_i, best);
        //     }
        //   }
        // }
        // goalAngle = best_i * SCAN_RESOLUTION; //wrong
        goalAngle = 0;

        scanBehaviorState = BEHAVIOR_SCAN_STATE_GOTO;
        DEBUG_PRINT("Going to chosen a=%i...\n", (int)goalAngle);
        sendScan();
      }
      break;
    case BEHAVIOR_SCAN_STATE_GOTO:
      vel->yawrate = ((goalAngle - currentAngle > 0) ? 1 : -1) * ROTATION_SPEED * 2;
      currentAngle += vel->yawrate * (float)(xTaskGetTickCount() - prevUpdateTime) / 1000.f;

      prevUpdateTime = xTaskGetTickCount();

      // Transition: go back to previous behavior when finished
      if(abs(goalAngle - currentAngle) < 2) {
        DEBUG_PRINT("Finished scan!\n");
        tunnelSetPreviousBehavior();
      }
      break;
  }

  // Collisions: disable avoider while scanning 
  *enableCollisions = false;
}