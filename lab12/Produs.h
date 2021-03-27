#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Produs
{
    char nume_produs[20];
    int cantitate;
    float pret_produs;
};

void creare_fisier(char *nume_fisier);
void afisare_ecran(char *nume_fisier);
void mysort(char *nume_fisier);
void find_produs(char *nume_fisier, char *nume_produs);
void find_replace(char *nume_fisier, char *nume_produs);
