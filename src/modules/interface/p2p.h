/**
 *    ||          ____  _ __
 * +------+      / __ )(_) /_______________ _____  ___
 * | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *  ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2011-2012 Bitcraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * p2p.h - CrazyRealtimeTransferProtocol stack
 */

#ifndef P2P_H_
#define P2P_H_

#include <stdint.h>
#include <stdbool.h>

#define P2P_MAX_DATA_SIZE 30

typedef enum {
  P2P_PORT_PING       = 0x00,
  P2P_PORT_PARAM      = 0x01,
  P2P_PORT_COMMANDER  = 0x02,
} P2PPort;

typedef struct _P2PPacket
{
  uint8_t size;                         //< Size of data (txdata or rxdata only)

  union {
    struct {
      union {
        uint8_t header;                 //< Header selecting channel and port
        struct {
          uint8_t port        : 4;      //< Selected P2P port
          uint8_t txdest      : 4;      //< Destination or origin address (0xE7E7E7E7EX with X=peer), used for sending only
        };
      };

      union {
        // Use when receiving a packet
        struct {
          union {
            uint8_t peers;                     //< Contains the two drones involved in this message
            struct {
              uint8_t rxdest      : 4;         //< Destination address (0xE7E7E7E7EX with X=peer)
              uint8_t origin      : 4;         //< Sender's address    (0xE7E7E7E7EX with X=peer)
            };
          };

          uint8_t rssi;                        //< Received RSSI

          uint8_t rxdata[P2P_MAX_DATA_SIZE-2]; //< Data when receiving
        };
        
        // Use when sending a packet
        uint8_t txdata[P2P_MAX_DATA_SIZE];     //< Data when sending 
      };
    };

    // Raw
    uint8_t raw[P2P_MAX_DATA_SIZE+1];  //< The full packet "raw" (header + data)
  };
} __attribute__((packed)) P2PPacket;

typedef void (*P2pCallback)(P2PPacket *);

/**
 * Initialize the P2P stack
 */
void p2pInit(void);

bool p2pTest(void);

/**
 * Initializes the queue and dispatch of an task.
 *
 * @param[in] taskId The id of the P2P task
 */
void p2pInitTaskQueue(P2PPort taskId);

/**
 * Register a callback to be called for a particular port.
 *
 * @param[in] port Crtp port for which the callback is set
 * @param[in] cb Callback that will be called when a packet is received on
 *            'port'.
 *
 * @note Only one callback can be registered per port! The last callback
 *       registered will be the one called
 */
void p2pRegisterPortCB(int port, P2pCallback cb);

/**
 * Put a packet in the TX task
 *
 * If the TX stack is full, the oldest lowest priority packet is dropped
 *
 * @param[in] p P2PPacket to send
 */
int p2pSendPacket(P2PPacket *p);

/**
 * Put a packet in the TX task
 *
 * If the TX stack is full, the function block until one place is free (Good for console implementation)
 */
int p2pSendPacketBlock(P2PPacket *p);

/**
 * Fetch a packet with a specidied task ID.
 *
 * @param[in]  taskId The id of the P2P task
 * @param[out] p      The P2P Packet with infomation (unchanged if nothing to fetch)
 *
 * @returns status of fetch from queue
 */
int p2pReceivePacket(P2PPort taskId, P2PPacket *p);

/**
 * Fetch a packet with a specidied task ID. Wait some time befor giving up
 *
 * @param[in]  taskId The id of the P2P task
 * @param[out] p      The P2P Packet with infomation (unchanged if nothing to fetch)
 * @param[in] wait    Wait time in milisecond
 *
 * @returns status of fetch from queue
 */
int p2pReceivePacketWait(P2PPort taskId, P2PPacket *p, int wait);

/**
 * Get the number of free tx packets in the queue
 *
 * @return Number of free packets
 */
int p2pGetFreeTxQueuePackets(void);

/**
 * Wait for a packet to arrive for the specified taskID
 *
 * @param[in]  taskId The id of the P2P task
 * @paran[out] p      The P2P Packet with information
 *
 * @return status of fetch from queue
 */
int p2pReceivePacketBlock(P2PPort taskId, P2PPacket *p);

/**
 * Print a packet's content to the debug console
 *
 * @param[in] p         A pointer to the packet to print info on
 * @paran[in] formatted Print the size, port, origin, destination, etc in a nice way
 * 
 * @note formatted==false will print the paquet as a simple hecadecimal array
 */
void p2pPrintPacket(P2PPacket *p, bool raw);

/**
 * Function pointer structure to be filled by the P2P link to permits P2P to
 * use manu link
 */
struct p2pLinkOperations
{
  int (*setEnable)(bool enable);
  int (*sendPacket)(P2PPacket *pk);
  int (*receivePacket)(P2PPacket *pk);
  bool (*isConnected)(void);
  int (*reset)(void);
};

void p2pSetLink(struct p2pLinkOperations * lk);

/**
 * Check if the connection timeout has been reached, otherwise
 * we will assume that we are connected.
 *
 * @return true if conencted, otherwise false
 */
bool p2pIsConnected(void);

/**
 * Reset the P2P communication by flushing all the queues that
 * contain packages.
 *
 * @return 0 for success
 */
int p2pReset(void);

#endif /*P2P_H_*/
