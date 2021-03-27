#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_replace(char *s, char *s1, char *s2)
{
    char *p, *aux = malloc(100 * sizeof(char));

    p = strstr(s, s1);
    strcpy(aux, s2);
    strcat(aux, p + strlen(s1));
    strcpy(p, aux);

    return s;
}

int main()
{
    char s[105], s1[105], s2[105];

    scanf("%s%s", s1, s2);
    fgets(s, 100, stdin); // citesc newline
    fgets(s, 100, stdin);

    char *p;
    p = strstr(s, s1);
    while (p != NULL)
    {
        my_replace(s, s1, s2);
        p = strstr(s, s1);
    }

    printf("%s", s);
}