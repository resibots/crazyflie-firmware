#include <stdio.h> 
#include "pid.h"
#include "stabilizer.h"
#include "stabilizer_types.h"

#include "sensfusion6.h"
#include "controller_pid_hexa.h"

#include "log.h"
#include "param.h"
#include "math3d.h"
#include "debug.h"
#include "led.h"
#include "ledseq.h"

#define UPDATE_DT (float)(1.0f/RATE_MAIN_LOOP)

PidObject pidX;
PidObject pidY;
PidObject pidZ;
PidObject pidQX;
PidObject pidQY;
PidObject pidQZ;

#define Hexa_PID_X_KP  1.0
#define Hexa_PID_X_KI  0.0
#define Hexa_PID_X_KD  5.0
#define Hexa_PID_X_INTEGRATION_LIMIT    20.0

#define Hexa_PID_Y_KP  1.0
#define Hexa_PID_Y_KI  0.0
#define Hexa_PID_Y_KD  5.0
#define Hexa_PID_Y_INTEGRATION_LIMIT   20.0

#define Hexa_PID_Z_KP  10.0
#define Hexa_PID_Z_KI  0.0
#define Hexa_PID_Z_KD  5.0
#define Hexa_PID_Z_INTEGRATION_LIMIT   200.0

#define Hexa_PID_QX_KP  10.0
#define Hexa_PID_QX_KI  0.0
#define Hexa_PID_QX_KD  5.0
#define Hexa_PID_QX_INTEGRATION_LIMIT    20.0

#define Hexa_PID_QY_KP  10.0
#define Hexa_PID_QY_KI  0.0
#define Hexa_PID_QY_KD  5.0
#define Hexa_PID_QY_INTEGRATION_LIMIT   20.0

#define Hexa_PID_QZ_KP  10.0
#define Hexa_PID_QZ_KI  0.0
#define Hexa_PID_QZ_KD  5.0
#define Hexa_PID_QZ_INTEGRATION_LIMIT     360.0
#define Hexa_mass 0.037 //37g in kg
#define Hexa_Ixx 0.000016
#define Hexa_Iyy 0.000016
#define Hexa_Izz 0.000029
// acceleration control
static float ax;
static float ay;
static float az;
// angular acceleration control
static float wx;
static float wy;
static float wz;
// setpoint control
static float sx;
static float sy;
static float sz;

//current position 
static float cx;
static float cy;
static float cz;

static bool isInit;
void controllerPidHexaInit(void)
{
  if(isInit)
  {
    return;
  }

  pidInit(&pidQX,  0, Hexa_PID_QX_KP,  Hexa_PID_QX_KI,  Hexa_PID_QX_KD, UPDATE_DT, 0, 0, 0);
  pidInit(&pidQY, 0, Hexa_PID_QY_KP, Hexa_PID_QY_KI, Hexa_PID_QY_KD, UPDATE_DT, 0, 0, 0);
  pidInit(&pidQZ,   0, Hexa_PID_QZ_KP,   Hexa_PID_QZ_KI,   Hexa_PID_QZ_KD, UPDATE_DT, 0, 0, 0);
  pidSetIntegralLimit(&pidQX,  Hexa_PID_QX_INTEGRATION_LIMIT);
  pidSetIntegralLimit(&pidQY, Hexa_PID_QY_INTEGRATION_LIMIT);
  pidSetIntegralLimit(&pidQZ,   Hexa_PID_QZ_INTEGRATION_LIMIT);

  pidInit(&pidX,  0, Hexa_PID_X_KP,  Hexa_PID_X_KI,  Hexa_PID_X_KD, UPDATE_DT, 0, 0, 0);
  pidInit(&pidY, 0, Hexa_PID_Y_KP, Hexa_PID_Y_KI, Hexa_PID_Y_KD, UPDATE_DT, 0, 0, 0);
  pidInit(&pidZ,   0, Hexa_PID_Z_KP,   Hexa_PID_Z_KI,   Hexa_PID_Z_KD, UPDATE_DT, 0, 0, 0);
  pidSetIntegralLimit(&pidX,  Hexa_PID_QX_INTEGRATION_LIMIT);
  pidSetIntegralLimit(&pidY, Hexa_PID_QY_INTEGRATION_LIMIT);
  pidSetIntegralLimit(&pidZ,   Hexa_PID_QZ_INTEGRATION_LIMIT);
  isInit = true;
  DEBUG_PRINT("Initializing PID Hexa \n");

}

bool controllerPidHexaTest(void)
{
  bool pass = isInit;

  return pass;
}
// Updates control to desired in drone frame accelerations that power distribution will need to apply
void controllerPidHexa(control_t *control, setpoint_t *setpoint,
                                         const sensorData_t *sensors,
                                         const state_t *state,
                                         const uint32_t tick)
{
  ledseqRun(LED_GREEN_R, seq_linkup);
  sx = setpoint->position.x;
  sy = setpoint->position.y;
  sz = setpoint->position.z;
  sx = state->position.x;
  sy = state->position.y;
  sz = state->position.z;
  pidSetDesired(&pidX, setpoint->position.x);
  pidSetDesired(&pidY, setpoint->position.y);
  pidSetDesired(&pidZ, setpoint->position.z);
  pidSetDesired(&pidQX, 0);
  pidSetDesired(&pidQY, 0);
  pidSetDesired(&pidQZ, 0);
  //Get Quaternion error by multiplication rather than by substraction
  struct quat current_attitude = mkquat(state->attitudeQuaternion.x, state->attitudeQuaternion.y, state->attitudeQuaternion.z, state->attitudeQuaternion.w);
  struct quat setpoint_attitude = mkquat(setpoint->attitudeQuaternion.x, setpoint->attitudeQuaternion.y, setpoint->attitudeQuaternion.z, setpoint->attitudeQuaternion.w);
  struct quat inv_attitude = qinv(current_attitude);
  struct quat q_error = qqmul(setpoint_attitude, inv_attitude);
  // Extracting only the vector part of the quaternion error
  struct vec p_error = mkvec(pidUpdate(&pidX, state->position.x, true), pidUpdate(&pidY, state->position.y, true),pidUpdate(&pidZ, state->position.z, true));
  // Rotating the error into hexarotor frame and converting it into desired forces and torques
  struct vec rotated_error = qvrot(inv_attitude, p_error);
  ax = (float)(Hexa_mass) * rotated_error.x;
  ay = (float)(Hexa_mass) * rotated_error.y;
  az = (float)(Hexa_mass) * rotated_error.z;
  wx = pidUpdate(&pidQX, q_error.x, true) * (float)(Hexa_Ixx);
  wy = pidUpdate(&pidQY, q_error.y, true) * (float)(Hexa_Iyy);
  wz = pidUpdate(&pidQZ, q_error.z, true) * (float)(Hexa_Izz);

  control->ax = ax;
  control->ay = ay;
  control->az = az;
  control->roll = wx;
  control->pitch = wy;
  control->yaw = wz;
}


LOG_GROUP_START(controller)
LOG_ADD(LOG_FLOAT, ax, &ax)
LOG_ADD(LOG_FLOAT, ay, &ay)
LOG_ADD(LOG_FLOAT, az, &az)
LOG_ADD(LOG_FLOAT, wx, &wx)
LOG_ADD(LOG_FLOAT, wy, &wy)
LOG_ADD(LOG_FLOAT, wz, &wz)
LOG_ADD(LOG_FLOAT, sx, &sx)
LOG_ADD(LOG_FLOAT, sy, &sy)
LOG_ADD(LOG_FLOAT, sz, &sz)
LOG_ADD(LOG_FLOAT, cx, &cx)
LOG_ADD(LOG_FLOAT, cy, &cy)
LOG_ADD(LOG_FLOAT, cz, &cz)
LOG_GROUP_STOP(controller)
