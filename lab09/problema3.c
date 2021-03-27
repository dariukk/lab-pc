#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char *timestr(struct tm t, char *time)
{
    // transform ora in char
    int i = 0;

    if (t.tm_hour == 0)
        time[i++] = '0', time[i++] = ' ';
    else
    {
        int x = t.tm_hour, nr = 0;
        while (x)
        {
            ++nr;
            x /= 10;
        }
        i = i + nr;

        while (t.tm_hour)
        {
            time[--i] = t.tm_hour % 10 + '0';
            t.tm_hour /= 10;
        }

        i = i + nr;
        time[i++] = ' ';
    }

    if (t.tm_min == 0)
        time[i++] = '0', time[i++] = ' ';
    else
    {
        int x = t.tm_min, nr = 0;
        while (x)
        {
            ++nr;
            x /= 10;
        }
        i = i + nr;

        while (t.tm_min)
        {
            time[--i] = t.tm_min % 10 + '0';
            t.tm_min /= 10;
        }

        i = i + nr;
        time[i++] = ' ';
    }

    if (t.tm_sec == 0)
        time[i++] = '0', time[i] = ' ';
    else
    {
        int x = t.tm_sec, nr = 0;
        while (x)
        {
            ++nr;
            x /= 10;
        }
        i = i + nr;

        while (t.tm_sec)
        {
            time[--i] = t.tm_sec % 10 + '0';
            t.tm_sec /= 10;
        }
    }
    return time;
}

int main()
{
    char time[105];
    struct tm t;

    t.tm_hour = 14;
    t.tm_min = 0;
    t.tm_sec = 27;

    timestr(t, time);

    printf("%s", time);
}