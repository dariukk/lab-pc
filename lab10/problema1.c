#include <stdio.h>
#include <math.h>

double integrala(double (*func)(double x), double a, double b, int n)
{
    double pas = (b - a) / n, ans = 0;

    for (int i = 0; i < n; ++i)
        ans += 1.0 * (func(a + i * pas) + func(a + (i + 1) * pas)) * pas / 2;

    return ans;
}

int main()
{
    printf("%lf\n", integrala(sin, 0, M_PI, 1000));
    printf("%lf", integrala(cos, 0, M_PI, 1000));
}