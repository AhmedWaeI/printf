#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/**
 * _printf - Printf function
 * @format: format string
 *
 * Return: Number of printed chars
 */
int _printf(const char *format, ...)
{
    int i, count = 0;
    char c;
    char *s;
    int len;
    va_list args;

    va_start(args, format);

    if (format == NULL)
        return (-1);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%' && format[i + 1] == '%')
        {
            write(1, &format[i], 1);
            i++;
            count++;
        }
        else if (format[i] == '%')
        {
            switch (format[i + 1])
            {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;

                case 's':
                    s = va_arg(args, char*);
                    if (s == NULL)
                        return (-1);
                    len = 0;
                    while (s[len] != '\0')
                        len++;
                    write(1, s, len);
                    count += len;
                    break;

                case 'i':
                case 'd':
                    int num = va_arg(args, int);
                    int digit_count = 0;
                    int is_negative = 0;

                    if (num == 0)
                    {
                        write(1, "0", 1);
                        count++;
                        break;
                    }

                    if (num < 0)
                    {
                        write(1, "-", 1);
                        is_negative = 1;
                        num = -num;
                        count++;
                    }

                    int temp = num;
                    while (temp != 0)
                    {
                        digit_count++;
                        temp /= 10;
                    }

                    char digits[digit_count];
                    for (int j = digit_count - 1; j >= 0; j--)
                    {
                        digits[j] = num % 10 + '0';
                        num /= 10;
                    }

                    write(1, digits, digit_count);
                    count += digit_count;

                    break;

                case '%':
                    write(1, &format[i], 1);
                    count++;
                    break;

                default:
                    return (-1);
            }
            i++;
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
    }

    va_end(args);
    return (count);
}
