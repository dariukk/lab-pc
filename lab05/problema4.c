#include <stdio.h>

int cmmc(int a, int b)
{
    int r, a1, b1;
    a1 = a;
    b1 = b;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return (a1 * b1) / a;
}

int main()
{
    int x1, x2, y1, y2, y;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    y = cmmc(y1, y2);
    x1 = x1 * (y / y1);
    x2 = x2 * (y / y2);
    printf("%d %d\n%d %d", x1, y, x2, y);
}