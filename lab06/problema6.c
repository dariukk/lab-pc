#include <stdio.h>

void spirala(int A[][100], int m, int n, int V[])
{
    int caz, okay = 1, i, j, num, k;

    // case 0 - down
    // case 1 - right
    // case 2 - up
    // case 3 - left

    i = 1;
    j = 1;
    caz = 0;
    num = 0;
    V[0] = A[1][1];
    k = 1;
    while (okay)
    {
        okay = 0;
        if (caz == 0)
            while (i < m - num)
            {
                V[k++] = A[++i][j];
                okay = 1;
            }
        else if (caz == 1)
            while (j < n - num)
            {
                V[k++] = A[i][++j];
                okay = 1;
            }
        else if (caz == 2)
            while (i > num + 1)
            {
                V[k++] = A[--i][j];
                okay = 1;
            }
        else
        {
            num++;
            while (j > num + 1)
            {
                V[k++] = A[i][--j];
                okay = 1;
            }
        }
        caz = (caz + 1) % 4;
    }
}

void afisare(int V[], int dim)
{
    for (int i = 0; i < dim; ++i)
        printf("%d ", V[i]);
}

int main()
{
    int n, m, a[100][100], V[10000];

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    spirala(a, n, m, V);
    afisare(V, n * m);
}