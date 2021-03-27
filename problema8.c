
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[105];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int suma, x, nr, maxsuma, maxx, maxnr;
    suma = a[1];
    x = maxx = 1;
    nr = maxnr = 1;
    maxsuma = suma;
    for (int i = 2; i <= n; ++i)
    {
        if (suma < 0)
        {
            suma = a[i];
            x = i;
            nr = 1;
        }
        else
        {
            suma += a[i];
            ++nr;
        }
        if (suma > maxsuma)
        {
            maxsuma = suma;
            maxnr = nr;
            maxx = x;
        }
    }
    for (int i = x; i <= maxx + maxnr - 1; ++i)
        printf("%d ", a[i]);
}