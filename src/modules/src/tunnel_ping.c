#include "tunnel_ping.h"
#include "tunnel_config.h"

#define DEBUG_MODULE "TUN"
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
static unsigned long pingStartTime = 0;

void sendPing(bool propagate) {
  DEBUG_PRINT("Sending ping...\n");
  P2PPacket p2p_p;

  if(getDroneId() == 0)
    p2p_p.txdest = 1;
  else if(getDroneId() == getNDrones() - 1)
    p2p_p.txdest = getNDrones() - 2;
  else
    reply.txdest = getDroneId() + 1;

  p2p_p.port      = P2P_PORT_PING;
  p2p_p.txdata[0] = (uint8_t)propagate; // propagate or not
  p2p_p.size      = 1;         // Consider data size only (no header)

  pingStartTime = xTaskGetTickCount();
  p2pSendPacket(&p2p_p);
}

void tunnelPingUpdate() {
  if(getDroneId() == 0 && xTaskGetTickCount() - pingStartTime > 500)
    sendPing(true);
}

void crtpTunnelPingHandler(CRTPPacket *p) {
  if(p->data[0] == 0x00) { // ask for a ping
    sendPing(p->data[1]);
  }

  //TODO put elsewhere
  else if(p->data[0] == 0x01) { // set number of drones
    setNDrones(p->data[1]);
    DEBUG_PRINT("Set nDrones=%i\n", getNDrones());

    P2PPacket p2p_p;
    p2p_p.txdest = 0x0F; // broadcast
    p2p_p.port   = P2P_PORT_PARAM;
    p2p_p.txdata[0] = getNDrones();
    p2p_p.size = 1;
    p2pSendPacket(&p2p_p);
    p2pSendPacket(&p2p_p);
    p2pSendPacket(&p2p_p);
  }
}

static void p2pPingHandler(P2PPacket *p) {
  uint8_t rssi = p->rssi;
  DEBUG_PRINT("Got ping:\n");
  p2pPrintPacket(p, true);

  // The first drone doesn't reply to propagating pings
  if(p->rxdest == getDroneId() && getDroneId() == 0 && p->rxdata[0] == 0x01) {
    uint16_t pingTime = xTaskGetTickCount() - pingStartTime;
    DEBUG_PRINT("Ping returned in %ims.\n", pingTime);
    ledseqRun(LED_GREEN_R, seq_testPassed);

    // Send a ping report to the PC (containes RSSI values between each drone)
    CRTPPacket p_log;
    p_log.port = CRTP_PORT_TUNNEL;
    p_log.channel = 0;
    memcpy(p_log.data, &p->rxdata[1], p->size - 1);
    p_log.size = p->size - 1;

    // Add our RSSI if there's room
    if(p_log.size < P2P_MAX_DATA_SIZE) {
      p_log.data[p_log.size] = rssi;
      p_log.size++;
    }

    // Add the ping time if there's room
    if(p_log.size < P2P_MAX_DATA_SIZE) {
      p_log.data[p_log.size] = (pingTime > 255) ? 255 : pingTime;
      p_log.size++;
    }

    crtpSendPacket(&p_log);
    return;
  }

  // Other drones reply or propagate the ping
  if(p->rxdest == getDroneId()) {
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
    else // reply back directly
      reply.txdest = p->origin;
    
    // Copy the previous data
    memcpy(reply.txdata, p->rxdata, p->size);
    reply.size = p->size;

    // Add our RSSI if there's room
    if(reply.size < P2P_MAX_DATA_SIZE) {
      reply.txdata[reply.size] = rssi;
      reply.size++;
    }

    ledseqRun(LED_GREEN_R, seq_linkup);
    p2pSendPacket(&reply);
  }
}

void tunnelPingInit() {
  p2pRegisterPortCB(P2P_PORT_PING,     p2pPingHandler);
}

bool tunnelPingTest() {
  return true;
}

