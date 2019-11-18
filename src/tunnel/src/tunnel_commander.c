/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_commander.c - Calculates and applies the drone's desired 
 *                      movement based on:
 *                        - Obstacles with the multiranger deck
 *                        - RSSI values between the nearby drones
 * 
 * Is part of the navigation stack (commander, avoider & behavior).
 */

#include "tunnel_commander.h"
#include "tunnel_config.h"
#include "tunnel_helpers.h"
#include "tunnel_avoider.h"
#include "tunnel_behavior.h"
#include "tunnel.h"

#define DEBUG_MODULE "TUN_CMD"
#include "debug.h"

#include "FreeRTOS.h"
#include "task.h"
#include "config.h"

#include "system.h"
#include "configblock.h"
#include "range.h"
#include "log.h"
#include "led.h"
#include "ledseq.h"

#include "crtp.h"
#include "p2p.h"
#include "commander.h"
#include "crtp_commander.h"
#include "estimator_kalman.h"

typedef enum {
  TUNNEL_COMMANDER_MOVE = 0x00,
  TUNNEL_COMMANDER_GOTO = 0x01
} TunnelCommanderRequest;

static TunnelHover currentMovement;
static TunnelHover manualMovement;
static float tunnelDistance = 0;
static uint32_t prevUpdate = 0;

void getEstimatedPos(point_t *pos) {
  estimatorKalmanGetEstimatedPos(pos);

#ifdef TUNNEL_QUAD_SHAPE_PLUS
  float backup_x = pos->x;
  pos->x = (pos->x   - pos->y) * SQRT2_2;
  pos->y = (backup_x + pos->y) * SQRT2_2;
#endif
}

void sendSetpointHover(TunnelHover *hover) {
  uint8_t type = 5; // hoverType, see crtp_commander_generic.c:71

#ifdef TUNNEL_QUAD_SHAPE_PLUS
  // https://fr.wikipedia.org/wiki/Rotation_plane#Formules_de_changement_d'axes_de_coordonn%C3%A9es
  float backup_vx = hover->vx;
  hover->vx = (hover->vx + hover->vy) * SQRT2_2;
  hover->vy = (hover->vy - backup_vx) * SQRT2_2;
#endif

  CRTPPacket pk;
  pk.port = CRTP_PORT_SETPOINT_GENERIC;
  pk.channel = 0;
  uint8_t *p = pk.data; memcpy(p, &type, sizeof(type));
  p += sizeof(type);    memcpy(p, &hover->vx, sizeof(hover->vx));
  p += sizeof(hover->vx);      memcpy(p, &hover->vy, sizeof(hover->vy));
  p += sizeof(hover->vy);      memcpy(p, &hover->yawrate, sizeof(hover->yawrate));
  p += sizeof(hover->yawrate); memcpy(p, &hover->zDistance, sizeof(hover->zDistance));
  pk.size = sizeof(type) + sizeof(hover->vx) + sizeof(hover->vy) + sizeof(hover->yawrate) + sizeof(hover->zDistance);

  setpoint_t setpoint;
  crtpCommanderGenericDecodeSetpoint(&setpoint, &pk);
  commanderSetSetpoint(&setpoint, COMMANDER_PRIORITY_CRTP);
}

void sendSetpointStop() {
  uint8_t type = 0; // stopType, see crtp_commander_generic.c:66
  CRTPPacket pk;
  pk.port = CRTP_PORT_SETPOINT_GENERIC;
  pk.channel = 0;
  memcpy(pk.data, &type, sizeof(type));
  pk.size = 1;

  setpoint_t setpoint;
  crtpCommanderGenericDecodeSetpoint(&setpoint, &pk);
  commanderSetSetpoint(&setpoint, COMMANDER_PRIORITY_CRTP);
}

float tunnelGetDistance() {
  return tunnelDistance;
}

void tunnelSetDistance(float distance) {
  tunnelDistance = distance;
}

TunnelHover *tunnelGetCurrentMovement() {
  return &currentMovement;
}

void tunnelCommanderUpdate() {
  // Red switch for tests
#ifdef TUNNEL_RED_SWITCH
  if(rangeGet(rangeUp) > 0 && rangeGet(rangeUp) < 100) {
    sendSetpointStop();
    tunnelSetDroneState(DRONE_STATE_CRASHED);
    ledseqRun(SYS_LED, seq_testPassed);
  }
#endif

  // Get desired movement from behavior
  bool enableCollisions = true;
  TunnelHover currentMovement;
  tunnelBehaviorUpdate(&currentMovement, &enableCollisions);

  // Get repulsion from avoider
  tunnelAvoiderUpdate(&currentMovement, enableCollisions);

  // Calculate final movement
  currentMovement.vx      += manualMovement.vx     ;
  currentMovement.vy      += manualMovement.vy     ;
  currentMovement.yawrate += manualMovement.yawrate;

  // Constrain the command values
  currentMovement.vx        = CONSTRAIN(-1 * TUNNEL_MAX_SPEED,      currentMovement.vx, TUNNEL_MAX_SPEED);
  currentMovement.vy        = CONSTRAIN(-1 * TUNNEL_MAX_SPEED,      currentMovement.vy, TUNNEL_MAX_SPEED);
  currentMovement.yawrate   = CONSTRAIN(-1 * TUNNEL_MAX_TURN_SPEED, currentMovement.yawrate, TUNNEL_MAX_TURN_SPEED);
  currentMovement.zDistance = CONSTRAIN(TUNNEL_MIN_HEIGHT,          currentMovement.zDistance, TUNNEL_MAX_HEIGHT);

  // Refresh the estimated distance in tunnel
  if(prevUpdate != 0)
    tunnelDistance += currentMovement.vx * (xTaskGetTickCount() - prevUpdate) / 1000.f;

  // Send the movement command (only when this module is allowed to send setpoints)
  if(tunnelGetDroneState() == DRONE_STATE_FLYING) {
    if(tunnelGetCurrentBehavior() != TUNNEL_BEHAVIOR_IDLE)
      sendSetpointHover(&currentMovement);
    else sendSetpointStop();

    prevUpdate = xTaskGetTickCount();
  }
}

static void tunnelCommanderProcessPacket(uint8_t* data) {
  switch(data[0]) {
    // Directly move the drone: rxdata = [TUNNEL_COMMANDER_XXXX][int8_t vx][int8_t vy]
    case TUNNEL_COMMANDER_MOVE:
      manualMovement.vx = TUNNEL_DEFAULT_SPEED * (float)(int8_t)data[1];
      manualMovement.vy = TUNNEL_DEFAULT_SPEED * (float)(int8_t)data[2];
      break;
    case TUNNEL_COMMANDER_GOTO:
      setBehaviorGotoGoal((float)data[1] / 10.f);
      tunnelSetBehavior(TUNNEL_BEHAVIOR_GOTO);
      break;
  }
}

void crtpTunnelCommanderHandler(CRTPTunnelPacket *p) {
  tunnelCommanderProcessPacket(p->dronedata);
}

void p2pTunnelCommanderHandler(P2PPacket *p) {
  if(p->rxdest == getDroneId())
    tunnelCommanderProcessPacket(p->rxdata);
}

void tunnelCommanderInit() {
  // Register commander callbacks. CRTP callback is called from tunnel.c
  p2pRegisterPortCB(P2P_PORT_COMMANDER, p2pTunnelCommanderHandler);

  // Initialize submodules
  tunnelAvoiderInit();
  tunnelBehaviorInit();

  // Initialize structures
  manualMovement.vx        = 0;
  manualMovement.vy        = 0;
  manualMovement.yawrate   = 0;
  manualMovement.zDistance = 0;
}

bool tunnelCommanderTest() {
  bool pass = true;

  pass &= tunnelAvoiderTest();
  pass &= tunnelBehaviorTest();

  return pass;
}
