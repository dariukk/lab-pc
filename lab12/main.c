#include "Produs.h"

int main(int argc, char *argv[])
{
    creare_fisier(argv[1]);
    find_replace(argv[1], "Produs10");
    afisare_ecran(argv[1]);
}

void creare_fisier(char *nume_fisier)
{
    FILE *out;
    out = fopen(nume_fisier, "wb");
    for (int i = 0; i < 100; ++i)
    {
        int x = rand();
        char str[100];
        struct Produs s;

        sprintf(str, "%d", x);
        strcpy(s.nume_produs, "Produs");
        strcat(s.nume_produs, str);
        s.cantitate = x % 100;
        s.pret_produs = x <= 100 ? x : x % 100;

        fwrite(&s, sizeof(s), 1, out);
    }
    fclose(out);
}

void afisare_ecran(char *nume_fisier)
{
    FILE *in;
    in = fopen(nume_fisier, "rb");
    struct Produs s;
    for (int i = 0; i < 100; ++i)
    {
        fread(&s, sizeof(s), 1, in);
        printf("%s %d %f\n", s.nume_produs, s.cantitate, s.pret_produs);
    }
    fclose(in);
}

void mysort(char *nume_fisier)
{
    FILE *in;
    in = fopen(nume_fisier, "rb");
    struct Produs vect[105];

    for (int i = 0; i < 100; ++i)
        fread(&vect[i], sizeof(struct Produs), 1, in);

    for (int i = 0; i < 100; ++i)
        for (int j = i + 1; j < 100; ++j)
            if (strcmp(vect[i].nume_produs, vect[j].nume_produs) == 1)
            {
                struct Produs aux;
                aux = vect[i];
                vect[i] = vect[j];
                vect[j] = aux;
            }

    for (int i = 0; i < 100; ++i)
        printf("%s %d %f\n", vect[i].nume_produs, vect[i].cantitate, vect[i].pret_produs);
}

void find_produs(char *nume_fisier, char *nume_produs)
{
    FILE *in;
    in = fopen(nume_fisier, "rb");
    int ok = 0;

    for (int i = 0; i < 100; ++i)
    {
        struct Produs s;
        fread(&s, sizeof(s), 1, in);
        if (strcmp(s.nume_produs, nume_produs) == 0)
        {
            ok = 1;
            printf("Date produs %s %d %f\n", s.nume_produs, s.cantitate, s.pret_produs);
        }
    }

    if (ok == 0)
        printf("Nu s-a gasit produsul");
}

void find_replace(char *nume_fisier, char *nume_produs)
{
    FILE *in;
    in = fopen(nume_fisier, "rb+");
    int ok = 0, pos;
    struct Produs replace, s;
    strcpy(replace.nume_produs, nume_produs);
    replace.cantitate = 420;
    replace.pret_produs = 420;
    fseek(in, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        fread(&s, sizeof(s), 1, in);
        if (strcmp(s.nume_produs, nume_produs) == 0)
        {
            ok = 1;
            pos = ftell(in) - sizeof(s);
            break;
        }
    }

    if (ok == 1)
    {
        fseek(in, pos, 0);
        s = replace;
        fwrite(&replace, sizeof(replace), 1, in);
    }

    if (ok == 0)
        printf("Nu s-a gasit produsul");

    fclose(in);
}