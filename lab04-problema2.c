
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, a[105], nrpoz;
    nrpoz = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] >= 0)
            nrpoz++;
    }
    printf("%d %d", n - nrpoz, nrpoz);
    return 0;
}