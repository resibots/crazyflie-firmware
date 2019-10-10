#ifndef __TUNNELCONFIG_H
#define __TUNNELCONFIG_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Red and green right-sided LEDs show if the drone senses obstacles on the sides
// #define TUNNEL_MULTIRANGER_LEDS

// Set tunnelCanFly to false (disable the motors) when putting a hand over the drone
#define TUNNEL_RED_SWITCH

// Choose which directions to avoid 
#define TUNNEL_AVOID_LEFTRIGHT
#define TUNNEL_AVOID_FRONTBACK
// #define TUNNEL_AVOID_UPDOWN //TODO

// At which distance in mm we should start avoiding obstacles
#define TUNNEL_RANGER_TRIGGER_DIST 1000

// When avoiding, push the drone away with this force (m/sec per ranging m)
#define TUNNEL_RANGER_AVOID_FORCE 0.3f

// Returns the number of drones to be considered in the chain
uint8_t getNDrones();

// Sets the number of drones in the chain
void setNDrones(uint8_t ndrones);

// Returns if the operator said the drone can fly
uint8_t getTunnelCanFly();

// Sets if the Tunnel module can use the motors
void setTunnelCanFly(uint8_t canfly);

// Get the last 4 bits of this drone's address
uint8_t getDroneId();

#endif