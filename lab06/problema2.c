#include <stdio.h>
#include <math.h>

void triangleWithVectors(double length[], double angle[])
{
    //the law of cosines
    //first angle
    angle[0] = 1.0 * (length[0] * length[0] + length[1] * length[1] - length[2] * length[2]) / (2 * length[0] * length[1]);
    angle[0] = acos(angle[0]) * 180.0 / M_PI;

    //second angle
    angle[1] = 1.0 * (length[1] * length[1] + length[2] * length[2] - length[0] * length[0]) / (2 * length[2] * length[1]);
    angle[1] = acos(angle[1]) * 180.0 / M_PI;

    //third angle
    angle[2] = 180 - angle[0] - angle[1];
}

void triangle(double l1, double l2, double l3, double *u1, double *u2, double *u3)
{
    //the law of cosines
    //first angle
    *u1 = 1.0 * (l1 * l1 + l2 * l2 - l3 * l3) / (2 * l1 * l2);
    *u1 = acos(*u1) * 180.0 / M_PI;

    //second angle
    *u2 = 1.0 * (l2 * l2 + l3 * l3 - l1 * l1) / (2 * l2 * l3);
    *u2 = acos(*u2) * 180.0 / M_PI;

    //third angle
    *u3 = 180 - *u1 - *u2;
}

int main()
{
    double l[3], angle[3];
    double u1, u2, u3;

    for (int i = 0; i < 3; ++i)
        scanf("%lf", &l[i]);

    triangle(l[0], l[1], l[2], &u1, &u2, &u3);
    triangleWithVectors(l, angle);

    printf("%.3lf %.3lf %.3lf\n", u1, u2, u3);
    for (int i = 0; i < 3; ++i)
        printf("%.3lf ", angle[i]);
}