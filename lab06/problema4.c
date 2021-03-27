#include <stdio.h>
#include <string.h>

int anotherStrcmp(char s1[], char s2[])
{
    for (int i = 0; i < strlen(s1) && i < strlen(s2); ++i)
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
    if (strlen(s1) == strlen(s2))
        return 0;
    if (strlen(s1) > strlen(s2))
        return 1;
    if (strlen(s1) < strlen(s2))
        return -1;
    return 0;
}

int main()
{
    char string1[105], string2[105];

    scanf("%s%s", string1, string2);

    printf("%d", anotherStrcmp(string1, string2));
}