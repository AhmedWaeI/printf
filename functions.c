#include "main.h"
int printstring(char* s, int len)
{
    write(1, s, len);
    return (0);
}
int printchar(char c)
{
    write(1, &c, 1);
    return (0);

}
unsigned long int strlen(const char* s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    return (i);
}
