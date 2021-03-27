#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *v;
    int cap;
    int n;
} vector;

void init_vector(vector *a, int nr)
{
    (*a).v = malloc(nr * sizeof(int));
    (*a).cap = nr;
    (*a).n = 0;
}

void adauga_vector(vector *a, int n)
{
    if ((*a).n + 1 == (*a).cap)
    {
        (*a).v = realloc((*a).v, (*a).cap * 2 * sizeof(vector *));
        (*a).cap *= 2;
    }
    (*a).v[(*a).n] = n;
    (*a).n = (*a).n + 1;
}

void scrie_vector(vector *a)
{
    for (int i = 0; i < (*a).n; ++i)
        printf("%d ", (*a).v[i]);
}

int main()
{
    vector my_vector;

    init_vector(&my_vector, 25);

    for (int i = 0; i <= 100; ++i)
        adauga_vector(&my_vector, i);

    scrie_vector(&my_vector);
}