#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format)
    {
        if (*format == '%')
        {
            // handle format specifier
            format++;  // skip the '%'

            if (*format == 'c')
            {
                // print a single character
                int c = va_arg(args, int);
                write(STDOUT_FILENO, &c, 1);
                printed_chars++;
            }
            else if (*format == 's')
            {
                // print a string
                char *s = va_arg(args, char *);
                while (*s)
                {
                    write(STDOUT_FILENO, s, 1);
                    s++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                // print a literal '%'
                write(STDOUT_FILENO, "%", 1);
                printed_chars++;
            }
        }
        else
        {
            // print a literal character
            write(STDOUT_FILENO, format, 1);
            printed_chars++;
        }

        format++;  // advance to the next character
    }

    va_end(args);

    return printed_chars;
}

