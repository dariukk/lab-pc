#include <stdio.h>
#include <string.h>

int verif(char *s)
{
    if (strcmp(s, "i") == 0)
        return 1;
    if (strcmp(s, "n") == 0)
        return 2;
    if (strcmp(s, "c") == 0)
        return 3;
    return 0;
}

char majuscula(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 'a' + c - 'A';
    return c;
}

int mystrstr(char s[], char cuv[])
{
    int ok;

    for (int i = 0; i < strlen(s) - strlen(cuv); ++i)
    {
        ok = 0;
        for (int j = 0; j < strlen(cuv); ++j)
            if (majuscula(s[i + j]) != majuscula(cuv[j]))
            {
                ok = 1;
                break;
            }
        if (ok == 0)
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int opt[5], i = 1, linie = 0, linii_output = 0;
    char paragraf[100];
    FILE *fisier;

    while (verif(argv[i]))
    {
        opt[verif(argv[i])] = 1;
        ++i;
    }

    fisier = fopen(argv[i], "r");

    while (fgets(paragraf, 100, fisier) != NULL)
    {
        char *p;
        ++linie;

        if (opt[1])
        {
            if (mystrstr(paragraf, argv[i + 1]))
            {
                if (opt[2])
                    printf("[%d] ", linie);
                printf("%s", paragraf);
                ++linii_output;
            }
        }
        else
        {
            p = strstr(paragraf, argv[2]);
            if (p != NULL)
            {
                if (opt[2])
                    printf("[%d] ", linie);
                printf("%s", paragraf);
                ++linii_output;
            }
        }
    }

    if (opt[3])
        printf("Numar total de linii: %d", linii_output);

    fclose(fisier);
}