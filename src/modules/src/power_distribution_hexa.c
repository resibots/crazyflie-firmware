/**
 *    ||          ____  _ __
 * +------+      / __ )(_) /_______________ _____  ___
 * | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *  ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2011-2016 Bitcraze AB
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
 * power_distribution_hexa.c - Crazyflie stock power distribution code
 */
#include "power_distribution.h"

#include "log.h"
#include "param.h"
#include "num.h"
#include "math3d.h"
#include "motors.h"

static bool motorSetEnable = false;

static struct {
  uint32_t m1;
  uint32_t m2;
  uint32_t m3;
  uint32_t m4;
  uint32_t m5;
  uint32_t m6;
} motorPower;

static struct {
  uint16_t m1;
  uint16_t m2;
  uint16_t m3;
  uint16_t m4;
  uint16_t m5;
  uint16_t m6;
} motorPowerSet;

static float m1;
static float m2;
static float m3;
static float m4;
static float m5;
static float m6;
static float f1;
static float f2;
static float f3;
static float f4;
static float f5;
static float f6;

static struct mat66 hexa_inverse_matrix = {{
{-7.902E+1, -3.030E+7, 8.748E+6, -4.823E+2, -7.364E+8, -1.177E+8},
{-2.624E+7, +1.515E+7, 8.748E+6, +6.378E+8, -3.682E+8, +1.177E+8},
{+2.624E+7, +1.515E+7, 8.748E+6, +6.378E+8, +3.682E+8, -1.177E+8},
{-4.913E+1, -3.030E+7, 8.748E+6, +2.422E+3, +7.364E+8, +1.177E+8},
{-2.624E+7, +1.515E+7, 8.748E+6, -6.378E+8, +3.682E+8, -1.177E+8},
{+2.624E+7, +1.515E+7, 8.748E+6, -6.378E+8, -3.682E+8, +1.177E+8}
}};
static float max_hexa_rotor_speed = 3000;
static float min_hexa_rotor_speed = 0;

void powerDistributionInit(void)
{
  motorsInit(motorMapDefaultBrushed);
}

bool powerDistributionTest(void)
{
  bool pass = true;

  pass &= motorsTest();

  return pass;
}

#define limitThrust(VAL) limitUint16(VAL)

void powerStop()
{
  motorsSetRatio(MOTOR_M1, 0);
  motorsSetRatio(MOTOR_M2, 0);
  motorsSetRatio(MOTOR_M3, 0);
  motorsSetRatio(MOTOR_M4, 0);
  motorsSetRatio(MOTOR_M5, 0);
  motorsSetRatio(MOTOR_M6, 0);
}

void powerDistribution(const control_t *control)
{
  //converting the desired forces given by the controller into a vec6
  struct vec6 at = mkvec6(control->ax, control->ay, control->az, control->roll, control->pitch, control->yaw);
  //computing the desired control from desired forces into desired squarred rotor speed
  struct vec6 u = mvmul6(hexa_inverse_matrix, at);
  // converting u into pwm
  float min_hexa_rotor_speed_squarred = min_hexa_rotor_speed * min_hexa_rotor_speed;
  float max_hexa_rotor_speed_squarred = max_hexa_rotor_speed * max_hexa_rotor_speed;
  float inv_delta_hexa_rotor_speed_squarred = 1/max_hexa_rotor_speed_squarred - min_hexa_rotor_speed_squarred;
  u = v6addscl(u, -min_hexa_rotor_speed_squarred);
  u = v6scl(u, inv_delta_hexa_rotor_speed_squarred);
  // reducing setpoint until it can be achieved. Reducing only component not related to stability
  while(u.x>1 | u.y>1 |u.z>1 |u.t>1 |u.u>1 |u.w>1)
  {
    at.x = at.x * 0.9;
    at.y = at.x * 0.9;
    at.w = at.x * 0.9;
    u = mvmul6(hexa_inverse_matrix, at);
    u = v6addscl(u, -min_hexa_rotor_speed_squarred);
    u = v6scl(u, inv_delta_hexa_rotor_speed_squarred);
  }
  u = v6sclamp(u, 0, 1);
  f1 =  u.x;
  f2 =  u.y;
  f3 =  u.z;
  f4 =  u.t;
  f5 =  u.u;
  f6 =  u.w;
  // converting fraction of motor power into fraction of pwm according to https://www.research-collection.ethz.ch/handle/20.500.11850/214143
  float b = 1.0326e-6;
  float a = 2.1302e-11;
  float c = 5.4845e-4;
  m1 = (-b + sqrt(b*b - 4 * a * (c - u.x)))/(2*a*65535);
  // m1 = (float)motorPower.m1 / (float)65536;
  m2 = (-b + sqrt(b*b - 4 * a * (c - u.y)))/(2*a*65535);
  // m2 = (float)motorPower.m2 / (float)65536;
  m3 = (-b + sqrt(b*b - 4 * a * (c - u.z)))/(2*a*65535);
  // m3 = (float)motorPower.m3 / (float)65536;
  m4 = (-b + sqrt(b*b - 4 * a * (c - u.t)))/(2*a*65535);
  // m4 = (float)motorPower.m4 / (float)65536;
  m5 = (-b + sqrt(b*b - 4 * a * (c - u.u)))/(2*a*65535);
  // m5 = (float)motorPower.m5 / (float)65536;
  m6 = (-b + sqrt(b*b - 4 * a * (c - u.w)))/(2*a*65535);
  // m6 = (float)motorPower.m6 / (float)65536;
  // scaling and setting motor pwm
  motorPower.m1 = limitThrust(m1*65535);
  motorPower.m2 = limitThrust(m2*65535);
  motorPower.m3 = limitThrust(m3*65535);
  motorPower.m4 = limitThrust(m4*65535);
  motorPower.m5 = limitThrust(m5*65535);
  motorPower.m6 = limitThrust(m6*65535);
  if (motorSetEnable)
  {
    motorsSetRatio(MOTOR_M1, motorPowerSet.m1);
    motorsSetRatio(MOTOR_M2, motorPowerSet.m2);
    motorsSetRatio(MOTOR_M3, motorPowerSet.m3);
    motorsSetRatio(MOTOR_M4, motorPowerSet.m4);
    motorsSetRatio(MOTOR_M5, motorPowerSet.m5);
    motorsSetRatio(MOTOR_M6, motorPowerSet.m6);
  }
  else
  {
    motorsSetRatio(MOTOR_M1, motorPower.m1);
    motorsSetRatio(MOTOR_M2, motorPower.m2);
    motorsSetRatio(MOTOR_M3, motorPower.m3);
    motorsSetRatio(MOTOR_M4, motorPower.m4);
    motorsSetRatio(MOTOR_M5, motorPower.m5);
    motorsSetRatio(MOTOR_M6, motorPower.m6);
    // motorsSetRatio(MOTOR_M1, 65535*6/6);
    // motorsSetRatio(MOTOR_M2, 65535*6/6);
    // motorsSetRatio(MOTOR_M3, 65535*6/6);
    // motorsSetRatio(MOTOR_M4, 65535*6/6);
    // motorsSetRatio(MOTOR_M5, 65535*6/6);
    // motorsSetRatio(MOTOR_M6, 65535*6/6);

  }
}

PARAM_GROUP_START(motorPowerSet)
PARAM_ADD(PARAM_UINT8, enable, &motorSetEnable)
PARAM_ADD(PARAM_UINT16, m1, &motorPowerSet.m1)
PARAM_ADD(PARAM_UINT16, m2, &motorPowerSet.m2)
PARAM_ADD(PARAM_UINT16, m3, &motorPowerSet.m3)
PARAM_ADD(PARAM_UINT16, m4, &motorPowerSet.m4)
PARAM_ADD(PARAM_UINT16, m5, &motorPowerSet.m5)
PARAM_ADD(PARAM_UINT16, m6, &motorPowerSet.m6)
PARAM_GROUP_STOP(ring)

LOG_GROUP_START(motor)
LOG_ADD(LOG_FLOAT, m1, &m1)
LOG_ADD(LOG_FLOAT, m2, &m2)
LOG_ADD(LOG_FLOAT, m3, &m3)
LOG_ADD(LOG_FLOAT, m4, &m4)
LOG_ADD(LOG_FLOAT, m5, &m5)
LOG_ADD(LOG_FLOAT, m6, &m6)
LOG_ADD(LOG_FLOAT, f1, &f1)
LOG_ADD(LOG_FLOAT, f2, &f2)
LOG_ADD(LOG_FLOAT, f3, &f3)
LOG_ADD(LOG_FLOAT, f4, &f4)
LOG_ADD(LOG_FLOAT, f5, &f5)
LOG_ADD(LOG_FLOAT, f6, &f6)
LOG_GROUP_STOP(motor)
