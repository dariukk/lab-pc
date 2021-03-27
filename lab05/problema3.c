#include <stdio.h>

int prim(int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    int d = 3;
    while (d <= n/2)
    {
        if (n % d == 0)
            return 0;
        d += 2;
    }
    return 1;
}

int main()
{
    int n;

    scanf("%d", &n);
    
    for (int i = 1; i <= n / 2; i++)
        if (prim(n - i) && prim(i))
            printf("%d+%d\n", i, n - i);
    return 0;
}