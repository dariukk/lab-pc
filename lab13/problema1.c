#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 200

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int N, i, x;
    int *v, *rez;
    printf("Introduceti dimensiunea vectorului:\n");
    scanf("%d", &N);

    v = calloc(N, sizeof(int));
    if (!v)
        printf("Nu am putut aloca memorie pentru v!\n");

    srand(time(NULL));
    for (i = 0; i < N; ++i)
        v[i] = (rand() % MAX_VALUE) + 1;

    for (i = 0; i < N; ++i)
        printf("%d ", *(v + i));
    printf("\n");

    qsort(v, N, sizeof(int), cmp);

    for (i = 0; i < N; ++i)
        printf("%d ", *(v + i));
    printf("\n");

    // cautare binara
    printf("Introduceti numarul ce va fi cautat!\n");
    scanf("%d", &x);

    rez = bsearch(&x, v, N, sizeof(int), cmp);
    if (rez != NULL)
        printf("Elementul se gaseste pe pozitia %ld!\n", rez - v + 1);
    else
        printf("Numarul %d nu a fost gasit in sir", x);

    free(v);
    return 0;
}