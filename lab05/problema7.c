#include <stdio.h>

int transforma(int n)
{
    int fr[10] = {0}, ans = 0;
    if (n == 0)
        fr[0]++;
    while (n > 0)
    {
        fr[n % 10]++;
        n /= 10;
    }
    if (fr[0] != 0)
    {
        for (int i = 9; i >= 0; --i)
            for (int j = 1; j <= fr[i]; ++j)
                ans = ans * 10 + i;
    }
    else
    {
        for (int i = 1; i <= 9; ++i)
            for (int j = 1; j <= fr[i]; ++j)
                ans = ans * 10 + i;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", transforma(n));
}