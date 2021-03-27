#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry
{
    void *key;
    void *value;
} entry;

typedef struct map
{
    entry **elem; // vectorul de elemente; este alocat si realocat dinamic
    int n_elem;   // numarul de elemente din vector
    int cap;      // capacitatea vectorului
} map;

void init(map *m, int cap)
{
    m->elem = malloc(cap * sizeof(entry));
    m->cap = cap;
    m->n_elem = 0;
}

int compareKey(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int compareEntry(const void *a, const void *b)
{
    return compareKey((entry *)a.key, (entry *)b.key);
}

void add(map *m, entry *e)
{
    int ok = 0;

    for (int i = 0; i < m->n_elem; ++i)
        if (compareEntry(m->elem[i], e) == 0)
        {
            ok = 1;
            break;
        }

    if (!ok)
    {
        if (m->cap == m->n_elem + 1)
        {
            m->elem = realloc(m->elem, sizeof(entry) * 2 * m->cap);
            m->cap *= 2;
        }
        m->n_elem++;

        m->elem[m->n_elem - 1]->key = malloc(100 * sizeof(char));
        m->elem[m->n_elem - 1]->value = malloc(100 * sizeof(char));

        strcpy(m->elem[m->n_elem - 1]->key, e->key);
        strcpy(m->elem[m->n_elem - 1]->value, e->value);

        printf("%s", (char *)m->elem[m->n_elem - 1]->key);
    }
}

void printEntry(const entry *e)
{
    printf("%s %s\n", (char *)e->key, (char *)e->value);
}

void print(map *m, void (*printEntry)(const entry *))
{
    if (m->n_elem == 0)
    {
        printf("Dictionarul nu contine niciun cuvant :(\n");
        return;
    }

    printf("Dicionarul este:\n");

    for (int i = 0; i < m->n_elem; ++i)
        printEntry(m->elem[i]);
}

void sort(map *m, int (*fc)(const void *, const void *))
{
    qsort(m->elem, m->n_elem, sizeof(entry), fc);
}

void del(map *m, void *k, int (*fc2)(const void *, const void *))
{
    for (int i = 0; i < m->n_elem; ++i)
        if (compareKey(k, m->elem[i]->key) == 0)
            free(m->elem[i]);
}

void *find(map *m, void *k, int (*fc)(const void *, const void *))
{
    entry *rez;

    rez = bsearch(&*(char *)k, m->elem, m->n_elem, sizeof(entry), fc);

    if (rez != NULL)
        printf("Am gasit cuvantul in dictionar\n");
    else
        printf("Cuvantul nu se afla in dcitiornar :(\n");
}

int main()
{
    printf("Optiuni dictionar :)\n");
    printf("1. - Afisare dictionar\n");
    printf("2. - Cauta cuvant in dictionar.\n");
    printf("3. - Adauga cuvant in dictionar.\n");
    printf("4. - Sterge cuvant din dictionar.\n");
    printf("5. - Sortare dictionar\n");
    printf("6. - Iesire din program\n\n");

    char input;
    struct map *m;

    m = malloc(sizeof(map));
    init(m, 100);

    while (1)
    {
        input = getchar();

        if (input == '1')
            print(m, printEntry);
        else if (input == '2')
        {
            char mykey[100];
            scanf("%s", mykey);
            find(m, mykey, compareEntry);
        }
        else if (input == '3')
        {
            struct entry *e;
            e = malloc(sizeof(entry));
            scanf("%s%s", (char *)e->key, (char *)e->value);
            add(m, e);
        }
        else if (input == '4')
        {
            char mykey[100];
            scanf("%s", mykey);
            del(m, mykey, compareKey);
        }
        else if (input == '5')
            sort(m, compareEntry);
        else
            break;
    }
}