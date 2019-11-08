/**
 * LARSEN Research team - INRIA
 * Multi-agent tunnel exploration module
 * 
 * author: Pierre Laclau <pierre.laclau@etu.utc.fr>
 * maintainer: LARSEN, INRIA Nancy Grand-Est, France
 *
 * tunnel_ping.c - Sends, processes and propagates ping requests
 * accross the drones chain. Used for reporting the chain status
 * to the operator and informing all drones of each other's status.
 */

#include "tunnel_ping.h"
#include "tunnel_config.h"
#include "tunnel_relay.h"
#include "tunnel.h"
#include "tunnel_behavior.h"
#include "tunnel_helpers.h"
#include "tunnel_comm.h"

#define DEBUG_MODULE "PING"
#include "debug.h"

#include "FreeRTOS.h"
#include "task.h"
#include "config.h"

#include "system.h"
#include "led.h"
#include "ledseq.h"

#include "crtp.h"
#include "p2p.h"

static P2PPacket reply;
static unsigned long pingPrevTime = 0;

// Private functions

static void sendCRTPPingReport(P2PPacket *p) {
  uint16_t pingTime = xTaskGetTickCount() - pingPrevTime;
  DEBUG_PRINT("Ping returned in %ims.\n", pingTime);

  CRTPTunnelPacket p_log;
  p_log.port = CRTP_PORT_TUNNEL;
  p_log.channel = 0;
  memcpy(p_log.basedata, &p->rxdata[1], p->size - 1);
  p_log.size = p->size - 1;

  // Add our RSSI+status if there's room
  if(p_log.size < CRTP_MAX_DATA_SIZE - 2) {
    p_log.basedata[p_log.size++] = p->rssi;
    p_log.size += appendStatusMessage(&p_log.basedata[p_log.size]);
  }

  // Add the ping time if there's room
  if(p_log.size < CRTP_MAX_DATA_SIZE) {
    p_log.basedata[p_log.size] = (pingTime > 255) ? 255 : pingTime;
    p_log.size++;
  }

  tunnelSendCRTPPacketToBase(&p_log);
}

static void detectBaseDrone(P2PPacket* p) {
  for(uint8_t i = 1; i < p->size; i += 3) {
    bool isConnected = p->rxdata[i] & 0x01;

    if(isConnected) {
      uint8_t baseDroneID = i / 3;
      if(baseDroneID >= getNDrones())
        baseDroneID -= (getNDrones() - 1) * 3;

      setBaseDroneID(baseDroneID);
      return;
    }
  }

  // If no one is connected, default to the tail drone
  setBaseDroneID(getNDrones() - 1);
}

static void processFinishedPing(P2PPacket *p) {
  // Send a ping report to the PC (containes RSSI values between each drone)
  sendCRTPPingReport(p);

  // Detect if a drone is connected to the base and update our drone estimate ID
  detectBaseDrone(p);

  // ledseqRun(LED_GREEN_R, seq_testPassed);
}

static void p2pPingHandler(P2PPacket *p) {
  // DEBUG_PRINT("Got ping:\n");
  // p2pPrintPacket(p, true);

  // Detect if a drone is connected to the base and update our drone estimate ID
  detectBaseDrone(p);

  // The first drone doesn't reply to propagating pings
  if(p->rxdest == getDroneId() && getDroneId() == 0 && p->rxdata[0] == 0x01) 
    processFinishedPing(p);

  // Other drones reply or propagate the ping
  else if(p->rxdest == getDroneId()) {
    // first byte tells if the ping has to propagate through the chain
    if(p->size >= 1 && p->rxdata[0] == 0x01) {
      reply.txdest = getDroneId();
      if(getDroneId() == 0) // first drone replies to second
        reply.txdest = 1;
      else if(getDroneId() == getNDrones() - 1) // last drone replies to n-1
        reply.txdest = getNDrones() - 2;
      else // middle drone propagates the ping
        reply.txdest += (p->rxdest - p->origin > 0) ? 1 : -1;
    }
    else reply.txdest = p->origin; // reply back directly
    
    // Copy the previous data
    memcpy(reply.txdata, p->rxdata, p->size);
    reply.size = p->size;
    reply.port = P2P_PORT_PING;

    // Add our RSSI+status if there's room
    if(reply.size < P2P_MAX_DATA_SIZE - 2) {
      reply.txdata[reply.size++] = p->rssi;
      reply.size += appendStatusMessage(&reply.txdata[reply.size]);
    }

    p2pSendPacket(&reply);
  }
}

// Public functions

void sendPing(bool propagate) {
  // DEBUG_PRINT("Sending ping...\n");
  P2PPacket p2p_p;

  if(getDroneId() == 0)
    p2p_p.txdest = 1;
  else if(getDroneId() == getNDrones() - 1)
    p2p_p.txdest = getNDrones() - 2;
  else
    reply.txdest = getDroneId() + 1;

  p2p_p.port      = P2P_PORT_PING;
  p2p_p.txdata[0] = (uint8_t)propagate; // propagate or not
  p2p_p.size = 1 + appendStatusMessage(&p2p_p.txdata[1]);
  p2pSendPacket(&p2p_p);
}

void tunnelPingUpdate() {
  // Drone-by-drone ping that adds the RSSI values
  if(getDroneId() == 0 && timerElapsed(&pingPrevTime, 1000))
    sendPing(true);
}

void crtpTunnelPingHandler(CRTPTunnelPacket *p) {
  sendPing(p->dronedata[0]);
}

void tunnelPingInit() {
  p2pRegisterPortCB(P2P_PORT_PING, p2pPingHandler);
}

bool tunnelPingTest() {
  return true;
}

