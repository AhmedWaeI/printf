#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * sum_them_all - calculates the sum of all its parameters
 * @n: number of arguments passed to the function
 *
 * Return: the resulting sum
 */
int _printf(const char* const format, ...)
{
    int i;
    int count = 0;
    char c;
    char* s;
    int len;
    va_list args;

    va_start(args, format);
    if (format == NULL)
    {
        return (-1);
    }
    if (format) {
        for (i = 0; format && format[i] != '\0'; i++)
        {
            if (format[i] == '%')
            {

                switch (format[i + 1])
                {
                case 'c':
                    c = va_arg(args, int);
                    printchar(c);
                    count++;
                    break;
                case 's':
                    s = va_arg(args, char*);
                    len = strlen(s);
                    printstring(s, len);
                    count = count + len;
                    break;



                }
            }
            if (!((format[i] == '%' || format[i - 1] == '%') && ((format[i + 1] == 's' || format[i + 1] == 'c') || (format[i] == 's' || format[i] == 'c'))))
            {
                printchar(format[i]);
                count++;
            }
        }
        va_end(args);
    }
    return (count);
}
