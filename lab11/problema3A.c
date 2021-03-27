#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char paragraf[100];
    FILE *fisier;

    fisier = fopen(argv[1], "r");

    while (fgets(paragraf, 100, fisier) != NULL)
    {
        char *p;
        p = strstr(paragraf, argv[2]);
        if (p != NULL)
            printf("%s", paragraf);
    }

    fclose(fisier);
}