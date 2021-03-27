#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char word[50];
    int aparitii;
} pereche;

int find_word(pereche *a, char word[100], int nr)
{
    for (int i = 0; i < nr; ++i)
        if (strcmp(word, (*(a + i)).word) == 0)
            return i;
    return -1;
}

void add_word(pereche *a, char word[100], int nr)
{
    strcpy((*(a + nr)).word, word);
    (*(a + nr)).aparitii = 1;
}

int main()
{
    pereche *a;
    int n, i = 1, nr = 0, cap = 2;
    char s[100];

    a = malloc(cap * sizeof(pereche));
    scanf("%d", &n);

    while (i <= n)
    {
        scanf("%s", s);
        if (strcmp(s, " ") != 0 && strcmp(s, "\n") != 0)
        {
            ++i;
            int ok = find_word(a, s, nr);
            if (ok == -1)
            {
                ++nr;
                add_word(a, s, nr - 1);
                if (nr == cap)
                {
                    cap *= 2;
                    a = realloc(a, cap * sizeof(pereche));
                }
            }
            else
                (*(a + ok)).aparitii = (*(a + ok)).aparitii + 1;
        }
    }

    for (int i = 0; i < nr; ++i)
        printf("%s %d\n", (*(a + i)).word, (*(a + i)).aparitii);
}