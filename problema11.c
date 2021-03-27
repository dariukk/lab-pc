
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c[55], n;
    double x;
    scanf("%lf %d", &x, &n);
    for (int i = 0; i <= n; ++i)
        scanf("%d", &c[i]);
    double ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = ans * x + c[i];
    printf("%.2lf", ans);
}