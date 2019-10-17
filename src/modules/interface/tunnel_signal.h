#ifndef __TUNNELSIGNAL_H
#define __TUNNELSIGNAL_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct {
  uint32_t timestamp;
  float rssi;
} SignalLog;

// Signal getters
SignalLog *tunnelGetFollowerSignal();
SignalLog *tunnelGetLeaderSignal();
SignalLog *tunnelGetBaseSignal();

// Signal setters, filters the value automatically
void tunnelSetFollowerSignal(uint8_t newRssi, float speed);
void tunnelSetLeaderSignal(uint8_t newRssi, float speed);
void tunnelSetBaseSignal(uint8_t newRssi, float speed);

// Initialize the param submodule
void tunnelSignalInit();

// Test if the param submodule initialized successfully
bool tunnelSignalTest();

#endif