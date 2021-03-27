#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vi = malloc(30 * sizeof(int));
    int *vim1 = malloc(30 * sizeof(int));
    int n, k;

    scanf("%d%d", &n, &k);

    *(vi) = *(vi + 1) = 1;
    for (int i = 2; i <= n; ++i)
    {
        int *aux = vi;
        vi = vim1;
        vim1 = aux;

        for (int j = 0; j <= i; ++j)
            *(vi + j) = *(vim1 + j) + *(vim1 + j - 1);
    }

    printf("%d", *(vi + k));
}