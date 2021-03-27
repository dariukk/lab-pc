#include <stdio.h>
#include <time.h>

int main()
{
    struct tm *data;
    time_t timp;

    timp = time(NULL);
    data = localtime(&timp);

    printf("%s", ctime(&timp));
    printf("%s", asctime(data));
}