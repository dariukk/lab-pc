
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[105][105], i, j, max, min, n, m;
    scanf("%d%d", &n, &m);
    scanf("%d", &a[1][1]);
    max = a[1][1];
    for (j = 2; j <= m; ++j)
    {
        scanf("%d", &a[1][j]);
        if (max < a[1][j])
            max = a[1][j];
    }
    min = max;
    for (i = 2; i <= n; ++i)
    {
        scanf("%d", &a[i][1]);
        max = a[i][1];
        for (j = 2; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
            if (max < a[i][j])
                max = a[i][j];
        }
        if (min > max)
            min = max;
    }
    printf("%d", min);
    return 0;
}