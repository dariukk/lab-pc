#include <stdio.h>
#include <stdlib.h>

struct multime
{
    unsigned char *a;
    unsigned int n;
};

void init(struct multime *m)
{
    (*m).a = calloc(100, sizeof(char));
}

int mypos(int x)
{
    int pos;
    if (x == 0)
        pos = 0;
    else if (x % 7 == 0)
        pos = x / 7 - 1;
    else
        pos = x / 7;
    return pos;
}

void add(struct multime *m, int x)
{
    int pos = mypos(x);

    (*m).a[pos] = (*m).a[pos] | (1 << (x - 7 * pos));
}

void del(struct multime *m, int x)
{
    int pos = mypos(x);

    (*m).a[pos] = (*m).a[pos] & (~(1 << (x - 7 * pos)));
}

void print(struct multime *m)
{
    for (int i = 0; i <= 99; ++i)
        if ((*m).a[mypos(i)] & (1 << (i - mypos(i) * 7)))
            printf("%d ", i);
    printf("\n");
}

int contains(struct multime *m, int x)
{
    int pos = mypos(x);

    if ((*m).a[pos] & (1 << (x - 7 * pos)))
        return 1;
    else
        return 0;
}

int main()
{
    struct multime a;
    int n, num;
    char type;

    init(&a);

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i)
    {
        scanf("%c", &type);
        if (type == 'A')
        {
            scanf("%d", &num);
            add(&a, num);
        }
        else if (type == 'D')
        {
            scanf("%d", &num);
            del(&a, num);
        }
        else if (type == 'C')
        {
            scanf("%d", &num);
            int ok = contains(&a, num);
            if (ok == 1)
                printf("DA\n");
            else
                printf("NU\n");
        }
        else
            print(&a);
        getchar();
    }
}