#ifndef __TUNNELSIGNAL_H
#define __TUNNELSIGNAL_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Used to keep track of the last time we have seen a drone
typedef struct {
  uint32_t timestamp;
  float rssi;
} SignalLog;

// Connection getters
bool tunnelIsDroneConnected(uint8_t id);
bool tunnelIsBaseConnected();

// Signal getters
SignalLog *tunnelGetFollowerSignal();
SignalLog *tunnelGetLeaderSignal();
SignalLog *tunnelGetBaseSignal();
SignalLog *tunnelGetUnfilteredSignal(uint8_t id);
SignalLog *tunnelGetSignal(uint8_t id);

// Initialize the param submodule
void tunnelSignalInit();

// Test if the param submodule initialized successfully
bool tunnelSignalTest();

#endif