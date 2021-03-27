#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verif(char *s1, char a, char b)
{
    // tratam cazul literelor mari
    int ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0;
    if (*s1 <= 'Z')
        ok1 = 'a' - 'A';
    if (a <= 'Z')
        ok2 = 'a' - 'A';
    if (*(s1 + 1) <= 'Z')
        ok3 = 'a' - 'A';
    if (b <= 'Z')
        ok4 = 'a' - 'A';

    if (*s1 + ok1 == a + ok2 && *(s1 + 1) + ok3 == b + ok4)
        return 1;
    return 0;
}

int main()
{
    char *s = malloc(10000 * sizeof(char));
    char word[100];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", word);

        if (i == 0)
            strcpy(s, word);
        else
        {
            if (verif(s + strlen(s) - 2, word[0], word[1]))
            {
                strcat(s, "-");
                strcat(s, word);
            }
        }
    }

    printf("%s", s);
}