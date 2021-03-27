#include <stdio.h>

void swap(int *num1, int *num2)
{
   int aux;
   aux = *num1;
   *num1 = *num2;
   *num2 = aux;
}

void bubbleSort(int a[], int n)
{
   for (int i = 0; i < n; ++i)
      for (int j = i; j < n - 1; ++j)
         if (a[i] > a[j + 1])
            swap(&a[i], &a[j + 1]);
}
int main()
{
   int n;
   int a[100];

   scanf("%d", &n);
   for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
   bubbleSort(a, n);

   for (int i = 0; i < n; ++i)
      printf("%d ", a[i]);
   return 0;
}