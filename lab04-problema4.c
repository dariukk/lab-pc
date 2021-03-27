
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a[105][105], b[105][105], c[105][105];
    int n, m, p, q;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    scanf("%d%d", &p, &q);
    for (int i = 1; i <= p; ++i)
        for (int j = 1; j <= q; ++j)
            scanf("%d", &b[i][j]);
    if (n != p)
        printf("\e[3mimposibil\e[0m");
    else
    {
        printf("%d %d\n",m,q);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= q; ++j)
                for (int k = 1; k <= n; ++k)
                    c[i][j] += a[i][k] * b[k][j];
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= q; ++j)
                printf("%d ", c[i][j]);
            printf("\n");
        }
    }
}