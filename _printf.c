#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

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

unsigned long int strlen(char* s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    return (i);
}

int _printf(const char* const format, ...)
{
    if (format == NULL) {
        return -1;
    }

    int count = 0;
    char buffer[BUFF_SIZE];
    int buff_ind = 0;
    va_list args;

    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;

            switch (format[i])
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    buffer[buff_ind++] = c;
                    if (buff_ind == BUFF_SIZE) {
                        printstring(buffer, buff_ind);
                        buff_ind = 0;
                    }
                    count++;
                    break;
                }
                case 's':
                {
                    char* s = va_arg(args, char*);
                    int len = strlen(s);
                    for (int j = 0; j < len; j++) {
                        buffer[buff_ind++] = s[j];
                        if (buff_ind == BUFF_SIZE) {
                            printstring(buffer, buff_ind);
                            buff_ind = 0;
                        }
                    }
                    count += len;
                    break;
                }
                case '%':
                {
                    buffer[buff_ind++] = '%';
                    if (buff_ind == BUFF_SIZE) {
                        printstring(buffer, buff_ind);
                        buff_ind = 0;
                    }
                    count++;
                    break;
                }
                default:
                    return -1;
            }
        }
        else
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE) {
                printstring(buffer, buff_ind);
                buff_ind = 0;
            }
            count++;
        }
    }

    printstring(buffer, buff_ind);

    va_end(args);

    return count;
}

