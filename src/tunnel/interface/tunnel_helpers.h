#ifndef __TUNNELHELPERS_H
#define __TUNNELHELPERS_H

#include "FreeRTOS.h"
#include "task.h"

// Pre-calculated constants for better performance
#define M_PI   (3.14159265358979323846f)
#define M_PI2  (1.57079632679f)
#define SQRT2_2 (0.70710678118654752440f) // sqrt(2)/2

// Common mathematical transformations
#define LINSCALE(domain_low, domain_high, codomain_low, codomain_high, value) (((codomain_high - codomain_low) / (domain_high - domain_low)) * (value - domain_low) + codomain_low)
#define CONSTRAIN(min, value, max) (value > max) ? max : ((value < min) ? min : value)

// Simple timer manager. Once the time has passed, resets the timer and returns true
static bool timerElapsed(unsigned long *prevTime, unsigned int duration) {
  bool result = xTaskGetTickCount() - *prevTime > duration;
  if(result) *prevTime = xTaskGetTickCount();
  return result;
}

#endif