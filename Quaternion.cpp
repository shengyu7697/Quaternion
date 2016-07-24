#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

// Right-Handed Coordinate Systems (same as OpenGL)
// pitch     yaw      roll
// attitude  heading  bank
// x         y        z
void EulerToQuaternion(float *quat, float pitch, float yaw, float roll)
{
    // Reference: https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Math/quaternion.cpp
    // Assuming the angles are in radians.
    float cp2 = cos(pitch * 0.5f);
    float cy2 = cos(yaw * 0.5f);
    float cr2 = cos(roll * 0.5f);
    float sp2 = sin(pitch * 0.5f);
    float sy2 = sin(yaw * 0.5f);
    float sr2 = sin(roll * 0.5f);

    quat[0] = cp2 * cy2 * cr2 + sp2 * sy2 * sr2; // w
    quat[1] = sp2 * cy2 * cr2 + cp2 * sy2 * sr2; // x
    quat[2] = cp2 * sy2 * cr2 - sp2 * cy2 * sr2; // y
    quat[3] = cp2 * cy2 * sr2 - sp2 * sy2 * cr2; // z
}

float DegreesToRadians(float degrees)
{
    return degrees * M_PI / 180;
}

float RadiansToDegrees(float radians)
{
    return radians * 180 / M_PI;
}

void test(float x, float y, float z)
{
    float quat[4] = {0};

    EulerToQuaternion(quat, DegreesToRadians(x), DegreesToRadians(y), DegreesToRadians(z));
    printf("%12f %12f %12f %12f\n", quat[0], quat[1], quat[2], quat[3]); // w x y z
}

int main()
{
    test(30, 0, 0);
    test(0, 30, 0);
    test(0, 0, 30);
    test(30, 60, 90);
    test(90, 30, 60);
    test(60, 90, 30);
    test(120, 150, 180);
    test(180, 120, 150);
    test(150, 180, 120);

    return 0;
}
