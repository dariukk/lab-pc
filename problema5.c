
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2;
    int a[1005], b[1005], c[1005];
    scanf("%d", &n1);
    for (int i = 1; i <= n1; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &n2);
    for (int i = 1; i <= n2; ++i)
        scanf("%d", &b[i]);
    int i, j, k;
    i = j = k = 1;
    while (i <= n1 && j <= n2)
    {
        if (a[i] > b[j])
            c[k++] = b[j++];
        else
            c[k++] = a[i++];
    }
    while (i <= n1)
        c[k++] = a[i++];
    while (j <= n2)
        c[k++] = b[j++];
    for (int i = 1; i <= n1 + n2; ++i)
        printf("%d ", c[i]);
    return 0;
}