#include <stdio.h>

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int arie_intersectie(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22)
{
    int distx, disty;
    distx = min(x12, x22) - max(x11, x21);
    disty = min(y11, y21) - max(y12, y22);
    if (distx * disty < 0)
        return 0;
    return distx * disty;
}

int main()
{
    int l1x, l1y, l2x, l2y, r1x, r1y, r2x, r2y;
    scanf("%d%d%d%d%d%d%d%d", &l1x, &l1y, &r1x, &r1y, &l2x, &l2y, &r2x, &r2y);
    printf("%d", arie_intersectie(l1x, l1y, r1x, r1y, l2x, l2y, r2x, r2y));
}