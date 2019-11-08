#ifndef __TUNNELCOMM_H
#define __TUNNELCOMM_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "crtp.h"

typedef struct {
  union {
    uint8_t status[2];

    struct {
      uint8_t isBaseConnected     : 1;
      uint8_t isFollowerConnected : 1;
      uint8_t isLeaderConnected   : 1;
      uint8_t isHead              : 1;

      uint8_t batteryVoltage      : 4;

      uint8_t currentBehavior     : 4;

      uint8_t droneState          : 4;
    };
  };
} TunnelStatus;

// Add the drone's status information in an array (usually a packet)
// Returns the number of bytes used
uint8_t appendStatusMessage(uint8_t *pkData);

// Update function that needs to be called regularly
void tunnelCommUpdate();

// Main callback when receiving a CRTP Packet from the base
void processIncomingCRTPPacket(CRTPTunnelPacket* p);

// Initialize the comm submodule
void tunnelCommInit();

// Test if the comm submodule initialized successfully
bool tunnelCommTest();

#endif