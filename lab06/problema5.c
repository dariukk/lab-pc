#include <stdio.h>

void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void transform(int v[], int n, int x)
{
    int num;

    for (int i = 0; i < n; ++i)
        if (v[i] < x)
        {
            num = i;
            for (int j = i - 1; j >= 0; --j)
                if (v[j] >= x)
                {
                    swap(&v[num], &v[j]);
                    num = j;
                }
                else
                    break;
        }
}

int main()
{
    int n, x, a[100];

    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    transform(a, n, x);

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
}