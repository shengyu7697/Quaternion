#ifndef QUATERNION_H
#define QUATERNION_H

void Euler2Quaternion(const float &pitch, const float &yaw, const float &roll, float *quat);
void Quaternion2Euler(const float *q, float &pitch, float &yaw, float &roll);
float Degrees2Radians(const float &degrees);
float Radians2Degrees(const float &radians);

#endif // QUATERNION_H
