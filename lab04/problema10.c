
#include <stdlib.h>
#include <stdio.h>
int a[1005],m,n;
float x[105];
int verif()
{
    for (int i = 1; i < m; ++i)
        if (a[i + 1] - a[i] <= 0)
            return 0;
    return 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%f", &x[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    if (verif() == 0)
        printf("Error");
    else
    {
        for (int j = 1; j < m; ++j)
        {
            int nr = 0;
            for (int i = 1; i <= n; ++i)
                if (a[j] < x[i] && x[i] < a[j + 1])
                    ++nr;
            printf("%d ", nr);
        }
    }
}