#include "main.h"
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int printstring(char *s, int len)
{
    return (write(1, s, len));
}

int printchar(char c)
{
    return (write(1, &c, 1));
}

unsigned long int _strlen(char *s)
{
    unsigned long int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    return (i);
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, &buffer[0], *buff_ind);
        *buff_ind = 0;
    }
}

int _printf(const char *format, ...)
{
    int i, count = 0, buff_ind = 0;
    char c, *s;
    int len, printed_chars = 0;
    va_list args;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(args, format);
    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            print_buffer(buffer, &buff_ind);

            switch (format[i + 1])
            {
            case 'c':
                c = va_arg(args, int);
                printed_chars += printchar(c);
                break;

            case 's':
                s = va_arg(args, char *);
                len = _strlen(s);
                printed_chars += printstring(s, len);
                break;

            case '%':
                printed_chars += printchar('%');
                break;

            default:
                printed_chars += printchar(format[i]);
                printed_chars += printchar(format[i + 1]);
                break;
            }
            i++;
        }
        else
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
                printed_chars += BUFF_SIZE;
            }
            else
            {
                printed_chars++;
            }
        }
    }
    va_end(args);
    print_buffer(buffer, &buff_ind);
    return (printed_chars);
}

