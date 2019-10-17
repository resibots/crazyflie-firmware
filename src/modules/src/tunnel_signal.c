/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_signal.c - Submodule for keeping track of RSSI values with 
 *                   other agents, applies a kalman filter on each agent
 */

#include "tunnel_signal.h"

#include "tunnel_config.h"
#include "tunnel_commander.h"
#include "p2p.h"
#include "radiolink.h"

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

// Private functions, used for filtering

static void kalmanUpdate(SignalLogFiltered *signal, float newRssi, float speed) {
  if(signal->signalLog.rssi == 0) {
    signal->signalLog.rssi = (1 / KALMAN_C) * newRssi;
    signal->cov = (1 / KALMAN_C) * TUNNEL_SIGNAL_KALMAN_Q * (1 / KALMAN_C);
  } else {
    float predRssi = (KALMAN_A * signal->signalLog.rssi) + (TUNNEL_SIGNAL_KALMAN_B * speed);
    float predCov  = ((KALMAN_A * signal->cov) * KALMAN_A) + TUNNEL_SIGNAL_KALMAN_R;

    // Kalman gain
    float K = predCov * KALMAN_C * (1 / ((KALMAN_C * predCov * KALMAN_C) + TUNNEL_SIGNAL_KALMAN_Q));

    // Correction
    signal->signalLog.rssi = predRssi + K * (newRssi - (KALMAN_C * predRssi));
    signal->cov = predCov - (K * KALMAN_C * predCov);
  }
}

static void tunnelP2PRssiHandler(P2PPacket* p) {
  if(p->origin == getFollowerID())
    kalmanUpdate(&followerSignal, p->rssi, tunnelGetCurrentMovement()->vx);
  if(p->origin == getLeaderID())
    kalmanUpdate(&leaderSignal, p->rssi, tunnelGetCurrentMovement()->vx);
  else {
    //TODO keep the last value of each message just in case, no filtering
  }
}

static void tunnelCRTPRssiHandler(uint8_t rssi) {
  kalmanUpdate(&baseSignal, rssi, tunnelGetCurrentMovement()->vx);
}

static void signalInit(SignalLogFiltered *signal) {
  signal->signalLog.timestamp = 0;
  signal->signalLog.rssi = 0;
}

// Public functions

SignalLog *tunnelGetFollowerSignal() { return &followerSignal.signalLog; }
SignalLog *tunnelGetLeaderSignal() { return &leaderSignal.signalLog; }
SignalLog *tunnelGetBaseSignal() { return &baseSignal.signalLog; }

void tunnelSignalInit() {
  // Initialize the structures with default values
  signalInit(&followerSignal);
  signalInit(&leaderSignal);
  signalInit(&baseSignal);

  // Subscribe to new RSSI values
  p2pRegisterRssiCB(tunnelP2PRssiHandler);
  radiolinkRegisterRssiCB(tunnelCRTPRssiHandler);
}

bool tunnelSignalTest() {
  return true;
}