#ifndef __TUNNELCONFIG_H
#define __TUNNELCONFIG_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

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