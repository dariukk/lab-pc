#include <stdio.h>
#include <string.h>

char *substr(char *src, int n, char *dest)
{
    strcpy(dest, src);
    strcpy(dest + n, "");
    return dest;
}
int main()
{
    char s[105], ans[105];
    int n1, pos, k;

    fgets(s, 100, stdin);
    n1 = strlen(s);
    s[n1 - 1] = '\0';
    --n1;

    scanf("%d%d", &pos, &k);
    substr(s + pos, k, ans);

    printf("%s", ans);
}