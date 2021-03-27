#include <stdio.h>

int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; ++i)
        fact *= i;
    return fact;
}

double putere(double x, int n)
{
    double ans = 1;
    for (int i = 1; i <= n; ++i)
        ans *= x;
    return ans;
}

double taylor(double x, int n)
{
    double ans = 1;
    for (int i = 1; i <= n; ++i)
        ans += putere(x, i) / factorial(i);
    return ans;
}

int main()
{
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    printf("%.4f", taylor(x, n));
}