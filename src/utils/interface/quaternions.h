#ifndef __QUATERNIONS_H
#define __QUATERNIONS_H
#include "matrix.h" 

typedef struct quaternion_s {
    float x;
    float y;
    float z;
    float w;
} base_quaternion_t;
typedef struct vec3_s {
    float x;
    float y;
    float z;
} base_vec3_t;

void quaternionConjugate(base_quaternion_t const q, base_quaternion_t* res);
void quaternionNormalize(base_quaternion_t const q, base_quaternion_t* res);
void quaternionInverse(base_quaternion_t const q, base_quaternion_t* res);
void quaternionMult(base_quaternion_t const q1, base_quaternion_t const q2, base_quaternion_t* res);
void quaternionVectorMult(base_quaternion_t const q, base_vec3_t const v, base_vec3_t* res);
/* void quaternionToEuler(base_quaternion_t q, euler_angles_t* res); */
/* void eulerToQuaternions(euler_angles_t e, base_quaternions_t* res); */
#endif
