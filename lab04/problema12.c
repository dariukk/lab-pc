
#include <stdio.h>
#include <stdlib.h>
int suma[1000005];
int main()
{
    int n, m, b, e, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &b, &e, &v);
        suma[b] += v;
        suma[e + 1] -= v;
    }
    for (int i = 1; i < n; ++i)
        suma[i] += suma[i - 1];
    for (int i = 0; i < n; ++i)
        printf("%d ", suma[i]);
}