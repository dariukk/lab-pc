#include <stdio.h>

typedef struct
{
    float re;
    float im;
} complex;

complex adunare(complex a, complex b)
{
    complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

complex scadere(complex a, complex b)
{
    complex c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}

complex inmultire(complex a, complex b)
{
    complex c;
    c.re = a.re * b.re - a.im * b.im;
    c.im = a.re * b.im + a.im * b.re;
    return c;
}

complex putere(complex a, int putere)
{
    if (putere == 0)
    {
        complex b;
        b.re = 1;
        b.im = 0;
        return b;
    }

    complex b;
    b = a;
    for (int i = 1; i < putere; ++i)
        b = inmultire(b, a);
    return b;
}

void scrie(complex a)
{
    printf("(%.3f,%.3f)\n", a.re, a.im);
}

int main()
{
    complex a;
    int n;
    int coef[100];

    printf("Dati grad : ");
    scanf("%d", &n);

    printf("Dati variabila : ");
    scanf("%f%f", &a.re, &a.im);

    printf("Dati coef : ");
    for (int i = 0; i <= n; ++i)
    {
        printf("X%d = ", i);
        scanf("%d", &coef[i]);
    }

    //Calculul polinomului

    complex ans;
    ans.re = ans.im = 0;
    for (int i = 0; i <= n; ++i)
    {
        complex aux;
        aux = putere(a, i);

        for (int j = 1; j < coef[i]; ++j)
            aux = adunare(aux, aux);

        ans = adunare(ans, aux);
        scrie(ans);
    }

    scrie(ans);
}