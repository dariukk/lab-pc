#include <stdio.h>
#include <string.h>

char *next(char *from, char *word)
{
    int n, i, k;
    n = strlen(from);
    i = 0;

    while (i < n)
        if (!(from[i] >= 'a' && from[i] <= 'z'))
            ++i;
        else
            break;
    k = 0;
    memset(word, 0, strlen(word));

    for (; i < n; ++i)
        if (from[i] >= 'a' && from[i] <= 'z')
            word[k++] = from[i];
        else
            break;

    char aux[105];
    strcpy(aux, from + i);
    strcpy(from, aux);

    return word;
}

int main()
{
    char s[105];

    fgets(s, 100, stdin);
    s[strlen(s) - 1] = '\0';
    char word[105];
    next(s, word);
    while (word[0] >= 'a' && word[0] <= 'z')
    {
        printf("%s ", word);
        next(s, word);
    }
}