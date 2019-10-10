#ifndef __TUNNELHELPERS_H
#define __TUNNELHELPERS_H

// Common structure used for the navigation stack (commander, avoider & behavior)
typedef struct {
  float vx;           // m/s in the body frame of reference
  float vy;           // m/s in the body frame of reference
  float yawrate;      // deg/s
  float zDistance;    // m in the world frame of reference
} TunnelHover;

#endif