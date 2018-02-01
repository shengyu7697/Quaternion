#include <iostream>
#include <stdio.h>
#include "Quaternion.h"

using namespace std;

void test(float x, float y, float z)
{
    float quat[4] = {0};

    Euler2Quaternion(Degrees2Radians(x), Degrees2Radians(y), Degrees2Radians(z), quat);
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
