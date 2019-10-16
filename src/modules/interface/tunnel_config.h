#ifndef __TUNNELCONFIG_H
#define __TUNNELCONFIG_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/****************
      DEBUG
*****************/

// Set tunnelCanFly to false (disable the motors) when putting a hand over the drone
#define TUNNEL_RED_SWITCH

// Default height used by all the movement behaviors
#define TUNNEL_DEFAULT_HEIGHT 0.3f

// Red and green right-sided LEDs show if the drone senses obstacles on the sides
// #define TUNNEL_MULTIRANGER_LEDS

/****************
 FLIGHT SETTINGS
*****************/

// Choose one quad direction configuration
// #define TUNNEL_QUAD_SHAPE_X    // Normal orientation
#define TUNNEL_QUAD_SHAPE_PLUS // Used to avoid obstacles with 4 distance sensors

// Max drone speed in m/s
#define TUNNEL_MAX_SPEED 0.6f

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
     RUNTIME
*****************/

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