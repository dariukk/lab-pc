#include <stdio.h>
#include <string.h>

char *strdel(char *p, int n)
{
    char aux[3005];
    strcpy(aux, p + n);
    strcpy(p, aux);
    return p;
}

char *strins(char *p, char *s)
{
    char aux[3005];
    strcpy(aux, p);
    strcpy(p, s);
    strcpy(p + strlen(s), aux);
    return p;
}

int main()
{
    char text[3005], s1[25], s2[25];
    int n1, n2;

    fgets(text, 3000, stdin);
    fgets(s1, 20, stdin);
    fgets(s2, 20, stdin);

    n1 = strlen(s1);
    n2 = strlen(s2);
    text[strlen(text) - 1] = '\0';
    s1[n1 - 1] = '\0';
    s2[n2 - 1] = '\0';
    --n1;
    --n2;

    char *p;
    p = strstr(text, s1);
    while (p != NULL)
    {
        strdel(p, n1);
        strins(p, s2);
        p = strstr(p + n2, s1);
    }

    printf("%s", text);
}