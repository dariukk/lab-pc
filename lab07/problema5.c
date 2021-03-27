#include <stdio.h>
#include <limits.h>

void panta(int x1, int y1, int x2, int y2, float *m, float *n)
{
    if (x1 == x2)
    {
        *m = INT_MAX;
        return;
    }
    *m = 1.0 * (y2 - y1) / (x2 - x1);
    *n = y1 - *m * x1;
}

int main()
{
    int x1, x2, x3, y1, y2, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    float m, n;
    panta(x1, y1, x2, y2, &m, &n);
    if (m == INT_MAX && x1 == x2)
    {
        if (x3 == x1)
            printf("DA");
        else
            printf("NU");
    }
    else if (m * x3 + n == y3)
        printf("DA");
    else
        printf("NU");
}