/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_signal.c - Submodule for keeping track of RSSI values with 
 *                   other agents, applies a kalman filter on the most
 *                   important agents (leader, follower and base)
 */

#include "tunnel_signal.h"

#include "tunnel_config.h"
#include "tunnel_commander.h"
#include "tunnel_comm.h"
#include "radiolink.h"
#include "p2p.h"

#include "FreeRTOS.h"
#include "task.h"

#define DEBUG_MODULE "SIG"
#include "debug.h"
#include "log.h"

//TODO keep track of all drones' statuses coming from pings ?

// Number of unfiltered signals (index corresponds to the agent id)
#define N_AGENTS 16

// Minimum time between two kalman updates
#define KALMAN_UPDATE_COOLDOWN 10

// Kalman global parameters
#define KALMAN_A 1.f // State vector
#define KALMAN_C 1.f // Measurement vector

typedef struct {
  SignalLog signalLog;
  float cov;
} SignalLogFiltered;

// Tracked signals
static SignalLogFiltered followerSignal;
static SignalLogFiltered leaderSignal;
static SignalLogFiltered baseSignal;
static SignalLog unfilteredSignals[N_AGENTS];

// Tracked statuses
static TunnelStatus followerStatus;
static TunnelStatus leaderStatus;

// Private functions, used for filtering

static void kalmanUpdate(SignalLogFiltered *signal, float newRssi, float speed) {
  if(signal->signalLog.rssi == 0) {
    signal->signalLog.rssi = (1 / KALMAN_C) * newRssi;
    signal->cov = (1 / KALMAN_C) * TUNNEL_SIGNAL_KALMAN_Q * (1 / KALMAN_C);
  } else if(xTaskGetTickCount() - signal->signalLog.timestamp > KALMAN_UPDATE_COOLDOWN) {
    float predRssi = (KALMAN_A * signal->signalLog.rssi) + (TUNNEL_SIGNAL_KALMAN_B * speed);
    float predCov  = ((KALMAN_A * signal->cov) * KALMAN_A) + TUNNEL_SIGNAL_KALMAN_R;

    // Kalman gain
    float K = predCov * KALMAN_C * (1 / ((KALMAN_C * predCov * KALMAN_C) + TUNNEL_SIGNAL_KALMAN_Q));

    // Correction
    signal->signalLog.rssi = predRssi + K * (newRssi - (KALMAN_C * predRssi));
    signal->cov = predCov - (K * KALMAN_C * predCov);
  }
  else return; // update the timestamp only when data has been refreshed
  signal->signalLog.timestamp = xTaskGetTickCount();
}

static void tunnelP2PRssiHandler(P2PPacket* p) {
  if(p->origin == getFollowerID())
    kalmanUpdate(&followerSignal, p->rssi, tunnelGetCurrentMovement()->vx);
  if(p->origin == getLeaderID())
    kalmanUpdate(&leaderSignal, p->rssi, tunnelGetCurrentMovement()->vx);
  else {
    unfilteredSignals[p->origin].timestamp = xTaskGetTickCount();
    unfilteredSignals[p->origin].rssi = p->rssi;
  }
}

static void tunnelCRTPRssiHandler(uint8_t rssi) {
  kalmanUpdate(&baseSignal, rssi, tunnelGetCurrentMovement()->vx);
}

static void p2pStatusHandler(P2PPacket *p) {
  if(p->origin == getLeaderID())
    memcpy(&leaderStatus, p->rxdata, sizeof(TunnelStatus));
  else if(p->origin == getFollowerID())
    memcpy(&followerStatus, p->rxdata, sizeof(TunnelStatus));
}

static void signalInit(SignalLog *signal) {
  signal->timestamp = 0;
  signal->rssi = 0;
}

// Public functions

bool tunnelIsDroneConnected(uint8_t id) {
  SignalLog *s = tunnelGetSignal(id);
  return s->rssi > 0 && s->rssi < TUNNEL_RSSI_DANGER &&
         (xTaskGetTickCount() - s->timestamp) < TUNNEL_DISCONNECT_TIMEOUT;
}

bool tunnelIsBaseConnected() {
  return logGetUint(logGetVarId("radio", "isConnected"));
}

SignalLog *tunnelGetFollowerSignal() { return &followerSignal.signalLog; }
SignalLog *tunnelGetLeaderSignal() { return &leaderSignal.signalLog; }
SignalLog *tunnelGetBaseSignal() { return &baseSignal.signalLog; }
SignalLog *tunnelGetUnfilteredSignal(uint8_t id) { 
  if(id >= N_AGENTS) return NULL;
  return &unfilteredSignals[id]; 
}
SignalLog *tunnelGetSignal(uint8_t id) {
  if(id == getFollowerID())
      return tunnelGetFollowerSignal();
  else if(id == getLeaderID())
    return tunnelGetLeaderSignal();
  else return tunnelGetUnfilteredSignal(id);
}

TunnelStatus *tunnelGetLeaderStatus() { return &leaderStatus; }
TunnelStatus *tunnelGetFollowerStatus() { return &followerStatus; }

void tunnelSignalInit() {
  // Initialize the structures with default values
  signalInit(&followerSignal.signalLog);
  signalInit(&leaderSignal.signalLog);
  signalInit(&baseSignal.signalLog);

  for(int i = 0; i < N_AGENTS; i++)
    signalInit(&unfilteredSignals[i]);

  // Subscribe to new statuses from leader & follower
  p2pRegisterPortCB(P2P_PORT_STATUS, p2pStatusHandler);

  // Subscribe to new RSSI values
  p2pRegisterRssiCB(tunnelP2PRssiHandler);
  radiolinkRegisterRssiCB(tunnelCRTPRssiHandler);
}

bool tunnelSignalTest() {
  return true;
}