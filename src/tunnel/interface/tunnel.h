#ifndef __TUNNEL_H
#define __TUNNEL_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Keeps track of the drone's state at the chain level
typedef enum {
  DRONE_STATE_INACTIVE = 0, // Drone is not in the selected drones allowed to fly
  DRONE_STATE_IDLE     = 1, // Drone waiting to be armed by it's leader
  DRONE_STATE_ARMED    = 2, // Drone waiting for the signal with its leader to get low
  DRONE_STATE_FLYING   = 3, // Drone flying and applying movement behaviors
  DRONE_STATE_CRASHED  = 4, // Have a beeper to make noise or something... :(
} DroneState;

// Keeps track of the drone's role in the chain
typedef enum {
  DRONE_ROLE_HEAD      = 0, // Applies the HeadMode requests by the operator
  DRONE_ROLE_RELAY     = 1, // Autonomous flight for relaying the head<->operator link
  DRONE_ROLE_BASE      = 2, // Stay on the ground, used for tests to fake the CRTP RSSI
} DroneRole;

// lets the user disable the autonomous mode if needed for tests
typedef enum {
  DRONE_MODE_MANUAL    = 0, // All states and behaviors are changed manually (for manual control or tests)
  DRONE_MODE_AUTO      = 1, // Automatically switch between drone states & auto positioning in the tunnel
} DroneMode;

// Get the current drone state
DroneState tunnelGetDroneState(); 

// Set the global drone state
void tunnelSetDroneState(DroneState newState);

// Get the current drone role
DroneRole tunnelGetDroneRole();

// Set the global drone role
void tunnelSetDroneRole(DroneRole newRole);

// Get the current drone mode
DroneMode tunnelGetDroneMode(); 

// Set the global drone mode
void tunnelSetDroneMode(DroneMode newMode);

// Initialize the tunnel submodule
void tunnelInit(void);

// Test if the tunnel submodule was correctly initialized
bool tunnelTest(void);

#endif