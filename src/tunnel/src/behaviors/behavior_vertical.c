#include "behavior_vertical.h"
#include "tunnel_behavior.h"

#include "tunnel.h"
#include "tunnel_config.h"
#include "estimator_kalman.h"

static float zTarget = 0.1f;
static uint32_t prevTime = 0;

static void verticalMotionUpdate(TunnelHover *vel, bool *enableCollisions, float direction) {
  // Inactive axis
  vel->vx = 0;
  vel->vy = 0;
  vel->yawrate = 0;

  // Handle resets
  if(prevTime == 0)
    prevTime = xTaskGetTickCount();

  // Disable collisions during vertical motions
  *enableCollisions = false;

  // Active axis: slowly increase the height
  zTarget += direction * TAKE_OFF_VELOCITY * (float)(xTaskGetTickCount() - prevTime) / 1000.f;
  prevTime = xTaskGetTickCount();
  vel->zDistance = zTarget;
}

// Take off

void behaviorTakeOffInit() {
  tunnelSetDroneState(DRONE_STATE_FLYING);
  zTarget = 0.1f;
  prevTime = 0;
  estimatorKalmanInit();
}

void behaviorTakeOffUpdate(TunnelHover *vel, bool *enableCollisions) {
  verticalMotionUpdate(vel, enableCollisions, 1.0);

  // Transitions: end the behavior when the default height is reached
  if(zTarget >= TUNNEL_DEFAULT_HEIGHT) {
    vel->zDistance = TUNNEL_DEFAULT_HEIGHT;
    tunnelSetDistance(0); // Reset distance estimation
    tunnelMarkTakeOffTime();

    switch(tunnelGetDroneRole()) {
    case DRONE_ROLE_HEAD:
      tunnelSetBehavior(TUNNEL_BEHAVIOR_HOVER);
      break;
    case DRONE_ROLE_RELAY:
      tunnelSetBehavior(TUNNEL_BEHAVIOR_POSITIONING);
      break;
    case DRONE_ROLE_BASE:
      tunnelSetBehavior(TUNNEL_BEHAVIOR_HOVER);
      break;
    }
  }
}

// Land

void behaviorLandInit() {
  zTarget = TUNNEL_DEFAULT_HEIGHT;
  prevTime = 0;
}

void behaviorLandUpdate(TunnelHover *vel, bool *enableCollisions) {
  verticalMotionUpdate(vel, enableCollisions, -1.0);

  // Transitions: end the behavior when the ground is reached
  if(zTarget <= 0.02f) {
    zTarget = 0;
    sendSetpointStop();
    tunnelSetBehavior(TUNNEL_BEHAVIOR_IDLE);
  }
}