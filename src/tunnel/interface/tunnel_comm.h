#ifndef __TUNNELCOMM_H
#define __TUNNELCOMM_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "crtp.h"

// Definition of the short status summary send between the drones
typedef struct {
  union {
    uint8_t status[2];

    struct {
      uint8_t isBaseConnected     : 1; // True if we received a CRTP packet in the last second
      uint8_t isFollowerConnected : 1; // True if we received a P2P packet from our follower in the last 500ms
      uint8_t isLeaderConnected   : 1; // True if we received a P2P packet from our follower in the last 500ms
      uint8_t isHead              : 1; // True if we currently are the head drone

      uint8_t batteryVoltage      : 4; // Current battery voltage from 0x00 to 0x0F (like a percentage)

      uint8_t currentBehavior     : 4; // Currently applied behavior enum id

      uint8_t droneState          : 4; // Current state enum id
    };
  };
} TunnelStatus;

// Channels protocol definition for base-to-drone CRTP packets
typedef enum {
  CRTP_TUNNEL_CHANNEL_PING          = 0x00,
  CRTP_TUNNEL_CHANNEL_PARAM         = 0x01,
  CRTP_TUNNEL_CHANNEL_COMMANDER     = 0x02,
  CRTP_TUNNEL_CHANNEL_COMMAND       = 0x03,
} CRTPTunnelChannel;

// Channels protocol definition for drone-to-base CRTP packets
typedef enum {
  CRTP_TUNNEL_RESPONSE_CHANNEL_PING = 0x00,
  CRTP_TUNNEL_RESPONSE_CHANNEL_SCAN = 0x01,
} CRTPTunnelResponseChannel;

// Add the drone's status information in an array (usually a packet). Returns the number of bytes used
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