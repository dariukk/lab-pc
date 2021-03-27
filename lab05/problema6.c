#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n, x[100], y[100];
    float max = 0;
    int p1, p2;

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
        
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (dist(x[i], y[i], x[j], y[j]) > max)
            {
                max = dist(x[i], y[i], x[j], y[j]);
                p1 = i;
                p2 = j;
            }
    printf("%d %d\n%d %d\n%f", x[p1], y[p1], x[p2], y[p2], max);
}