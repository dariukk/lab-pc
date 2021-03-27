#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

struct MATERIA
{
    char nume[15];
    int ore_curs;
    enum examen
    {
        C,
        S,
        A
    } tip_examen;
} PROGRAMA[MAX];

int verif(struct MATERIA a)
{
    for (int i = 0; i < strlen(a.nume); ++i)
        if (!((a.nume[i] >= 'a' && a.nume[i] <= 'z') ||
              (a.nume[i] >= 'A' && a.nume[i] <= 'Z') || a.nume[i] == ' ' || a.nume[i] == '\n'))
            return 0;

    if (a.ore_curs <= 0)
        return 0;

    if (!(a.tip_examen == 'C' || a.tip_examen == 'S' || a.tip_examen == 'A'))
        return 0;

    return 1;
}

int citire_MAT(struct MATERIA *a)
{
    char aux[5];
    fgets((*a).nume, 15, stdin);
    (*a).nume[strlen((*a).nume) - 1] = '\0';

    fgets(aux, 5, stdin);
    (*a).ore_curs = atoi(aux);

    fgets(aux, 5, stdin);
    (*a).tip_examen = aux[0];

    return verif((*a));
}

void citire_PROGRAMA()
{
    int ok;

    for (int i = 0; i < MAX; ++i)
    {
        ok = citire_MAT(&PROGRAMA[i]);
        if (ok == 0)
            printf("Date introduse gresit\n");
    }
}

void afisare_PROGRAMA(char examen, int ore)
{
    for (int i = 0; i < MAX; ++i)
        if (PROGRAMA[i].tip_examen == examen && PROGRAMA[i].ore_curs == ore)
            printf("%s %d %c\n", PROGRAMA[i].nume, PROGRAMA[i].ore_curs, PROGRAMA[i].tip_examen);
}

int main()
{
    citire_PROGRAMA();
    afisare_PROGRAMA('S', 10);
}