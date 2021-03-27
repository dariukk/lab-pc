
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[105][105];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i - 1; ++j)
            printf("%d ", a[n - i + j + 1][i]);
    return 0;
}