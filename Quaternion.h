#ifndef QUATERNION_H
#define QUATERNION_H

void Euler2Quaternion(float pitch, float yaw, float roll, float *quat);
void Quaternion2Euler(float *q, float &pitch, float &yaw, float &roll);
float Degrees2Radians(float degrees);
float Radians2Degrees(float radians);

#endif // QUATERNION_H
