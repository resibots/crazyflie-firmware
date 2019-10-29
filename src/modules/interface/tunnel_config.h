#ifndef __TUNNELCONFIG_H
#define __TUNNELCONFIG_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/****************
      MAIN
*****************/

// Default number of active drones, can be changed at runtime
#define DEFAULT_N_DRONES 3

// Main tunnel loop frequency rate
#define TUNNEL_TASK_RATE_HZ 20

/****************
      DEBUG
*****************/

// Set tunnelCanFly to false (disable the motors) when putting a hand over the drone
#define TUNNEL_RED_SWITCH

// Default height used by all the movement behaviors
#define TUNNEL_DEFAULT_HEIGHT 0.3f

// Even when centering in the tunnel, constrain the height (e.g. for the flow sensor)
#define TUNNEL_MIN_HEIGHT 0.f
#define TUNNEL_MAX_HEIGHT 0.5f

// Red and green right-sided LEDs show if the drone senses obstacles on the sides
// #define TUNNEL_MULTIRANGER_LEDS

/****************
 FLIGHT SETTINGS
*****************/

// Choose one quad direction configuration
#define TUNNEL_QUAD_SHAPE_X    // Normal orientation, uses 2 avoiding sensors
// #define TUNNEL_QUAD_SHAPE_PLUS // Used to avoid obstacles with 4 distance sensors

// Max drone speed in m/s
#define TUNNEL_MAX_SPEED 0.6f

// Default drone speed in m/s used in behaviors 
#define TUNNEL_DEFAULT_SPEED 0.3f

// Max drone yaw speed in deg/s
#define TUNNEL_MAX_TURN_SPEED 30.f

// Take off and landing speeds (m/s)
#define TAKE_OFF_VELOCITY 0.2f

/****************
OBSTACLE AVOIDING
*****************/

// Choose which directions to avoid 
#define TUNNEL_AVOID_LEFTRIGHT
// #define TUNNEL_AVOID_FRONTBACK

// At which distance in mm we should start avoiding obstacles
#define TUNNEL_RANGER_TRIGGER_DIST 1000

// When avoiding walls, push the drone away with this force (m/sec per ranging m)
#define TUNNEL_RANGER_AVOID_FORCE 1.f

// Enable yaw for keeping the head towards the tunnel direction (handle tunnel turns)
#define TUNNEL_TURNING_ENABLE // Uses 2 or 4 sensors based on TUNNEL_QUAD_SHAPE

// When avoiding walls, turn the drone based on the left-right distance difference (deg/s per mm)
#define TUNNEL_RANGER_TURN_FORCE .1f

/****************
      SIGNAL
*****************/

// RSSI Thresholds used in movement behaviors and state decisions
#define TUNNEL_RSSI_BEST    40 // Best quality considered (used not to go too close from another drone)
#define TUNNEL_RSSI_ARMED   60 // Quality to reach before taking off as a new follower drone
#define TUNNEL_RSSI_DANGER  70 // Threshold before considering the connection will soon be lost
#define TUNNEL_RSSI_MAXIMUM 80 // TODO useful?

// Process noise in the RSSI kalman filtering
#define TUNNEL_SIGNAL_KALMAN_R 0.01f

// Measurement noise in the RSSI kalman filtering
#define TUNNEL_SIGNAL_KALMAN_Q 5.f

// Control vector, predict an evolution based on the drone's current speed
#define TUNNEL_SIGNAL_KALMAN_B 3.f

/****************
     RUNTIME
*****************/

// Returns the current follower's ID
uint8_t getFollowerID();

// Sets the current follower's ID
void setFollowerID(uint8_t newID);

// Returns the current leader's ID
uint8_t getLeaderID();

// Sets the current leader's ID
void setLeaderID(uint8_t newID);

// Sets the drone's follower and leader to ID-1 and ID+1
void tunnelAutoSetFollowerLeader();

// Returns the number of drones to be considered in the chain
uint8_t getNDrones();

// Sets the number of drones in the chain
void setNDrones(uint8_t ndrones);

// Returns if the operator said the drone can fly
uint8_t getTunnelCanFly();

// Sets if the Tunnel module can use the motors
void setTunnelCanFly(bool canfly);

// Get the last 4 bits of this drone's address
uint8_t getDroneId();

#endif