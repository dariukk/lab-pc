#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v = malloc(5 * sizeof(int));
    int cap = 5, n;

    cap = 5;
    n = 0;
    scanf("%d", &*(v + n));
    while (*(v + n) != 0)
    {
        ++n;
        if (n == cap)
        {
            cap *= 2;
            v = realloc(v, cap * sizeof(int));
        }
        scanf("%d", &*(v + n));
    }

    //verificarea sirului
    for (int i = 0; i < n; ++i)
        printf("%d ", *(v + i));
}