#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n, m;
    int **a;
} MATRICE;

MATRICE *creeaza_MATRICE(int n, int m)
{
    MATRICE *ma = malloc(100 * sizeof(MATRICE));
    (*ma).a = malloc((n + 1) * sizeof(int));

    for (int i = 0; i < n; ++i)
        (*ma).a[i] = malloc((m + 1) * sizeof(int));

    (*ma).m = m;
    (*ma).n = n;

    return ma;
}

MATRICE *citeste_MATRICE(MATRICE *ma)
{
    for (int i = 0; i < (*ma).n; ++i)
        for (int j = 0; j < (*ma).m; ++j)
            scanf("%d", &(*ma).a[i][j]);
    return ma;
}

void scrie_MATRICE(MATRICE *ma)
{
    for (int i = 0; i < (*ma).n; ++i)
    {
        for (int j = 0; j < (*ma).m; ++j)
            printf("%d ", (*ma).a[i][j]);
        printf("\n");
    }
}

MATRICE *aduna_MATRICE(MATRICE *ma, MATRICE *mb)
{
    MATRICE *mc;
    mc = creeaza_MATRICE(3, 3);

    if (!((*ma).n == (*mb).n && (*ma).m == (*mb).m))
        return NULL;

    (*mc).m = (*ma).m;
    (*mc).n = (*ma).n;
    for (int i = 0; i < (*ma).n; ++i)
        for (int j = 0; j < (*ma).m; ++j)
            (*mc).a[i][j] = (*ma).a[i][j] + (*mb).a[i][j];

    return mc;
}

MATRICE *inmulteste_MATRICE(MATRICE *ma, MATRICE *mb)
{
    MATRICE *mc;
    mc = creeaza_MATRICE(3, 3);

    if ((*ma).m != (*mb).n)
        return NULL;

    for (int i = 0; i < (*ma).n; ++i)
        for (int j = 0; j < (*mb).m; ++j)
            for (int k = 0; k < (*ma).m; ++k)
                (*mc).a[i][j] += (*ma).a[i][k] * (*mb).a[k][j];

    return mc;
}

int main()
{
    MATRICE *A, *B, *C;

    A = creeaza_MATRICE(3, 3);
    B = creeaza_MATRICE(3, 3);

    citeste_MATRICE(A);
    citeste_MATRICE(B);

    C = aduna_MATRICE(A, B);
    scrie_MATRICE(C);

    printf('\n');

    C = inmulteste_MATRICE(A, B);
    scrie_MATRICE(C);
}