#include <stdio.h>

void commonElements(int a[], int sizeA, int b[], int sizeB, int c[], int *sizeC)
{
    *sizeC = 0;

    for (int i = 0; i < sizeA; ++i)
        for (int j = 0; j < sizeB; ++j)
            if (a[i] == b[j])
            {
                c[*sizeC] = a[i];
                *sizeC=*sizeC+1;
                break;
            }
}

int main()
{
    int a[1005], b[1005], c[1005];
    int n, m, num;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);

    commonElements(a, n, b, m, c, &num);

    printf("%d\n", num);
    for (int i = 0; i < num; ++i)
        printf("%d ", c[i]);
}