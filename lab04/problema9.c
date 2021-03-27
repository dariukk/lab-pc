
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[105];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int zero, neg, poz;
    for (int i = 2; i <= n; ++i)
        if (a[i] - a[i - 1] > 0)
            poz++;
        else if (a[i] - a[i - 1] < 0)
            neg++;
        else
            zero++;
    if (zero == n - 1)
        printf("constant");
    else if (poz + zero == n - 1)
        printf("crescator");
    else if (neg + zero == n - 1)
        printf("descrescator");
    else
        printf("neordonat");
}