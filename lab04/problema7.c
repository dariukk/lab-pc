
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[105];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int j = 1, nr, max, y, ymax;
    max = 0;
    nr = 1;
    y = 1;
    for (int i = 2; i <= n; ++i)
        if (a[i] < a[i - 1])
        {
            if (max < nr)
            {
                max = nr;
                ymax = y;
                nr = 1;
                y = i;
            }
        }
        else
            nr++;

    for (int i = ymax; i <= max + ymax - 1; ++i)
        printf("%d ", a[i]);
}