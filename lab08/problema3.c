#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **word = malloc(1005 * sizeof(*word)), s[20];
    int *a = malloc(1005 * sizeof(int)), n, cap = 0;

    scanf("%d", &n);
    for (int k = 0; k < n; ++k)
    {
        scanf("%s", s);

        if (strcmp(s, "\n") == 0 || strcmp(s, " ") == 0)
            continue;

        int ok = 0;

        for (int i = 0; i < cap; ++i)
            if (strcmp(*(word + i), s) == 0)
            {
                *(a + i) = *(a + i) + 1;
                ok = 1;
                break;
            }

        if (ok == 0)
        {
            *(a + cap) = 1;
            *(word + cap) = malloc(20 * sizeof(char));
            strcpy(*(word + cap), s);
            ++cap;
        }
    }

    for (int i = 0; i < cap; ++i)
        printf("%s %d\n", *(word + i), *(a + i));
}