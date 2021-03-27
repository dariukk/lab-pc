#include <stdio.h>
#include <string.h>
char criptare(char c, int cod[])
{
    if (c >= 'A' && c <= 'Z')
    {
        if (cod[c - 'A'] == -1)
            return c;
        return 'A' + cod[c - 'A'];
    }
    if (c >= 'a' && c <= 'z')
    {
        if (cod[c - 'a'] == -1)
            return c;
        return 'a' + cod[c - 'a'];
    }
    return c;
}

int main(int argc, char *argv[])
{
    FILE *in, *out, *encode;
    int cod[30];
    char s[100];

    encode = fopen(argv[1], "r");
    in = fopen(argv[2], "r");
    out = fopen(argv[3], "w");

    for (int i = 0; i <= 'Z' - 'A'; ++i)
        cod[i] = -1;

    while (fgets(s, 100, encode) != NULL)
        cod[s[0] - 'a'] = s[2] - 'a';

    while (fgets(s, 100, in) != NULL)
    {
        for (int i = 0; i < strlen(s); ++i)
            s[i] = criptare(s[i], cod);
        fprintf(out, "%s", s);
    }

    fclose(out);
    fclose(in);
    fclose(encode);
}