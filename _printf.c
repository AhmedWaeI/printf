#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int printstring(char* s, int len)
{
    write(1, s, len);
    return (0);
}
/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printchar(char c)
{
    write(1, &c, 1);
    return (0);

}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
unsigned long int strlen(const char* s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    return (i);
}
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
void print_intt(int num) {
    char str[10];
    int i = 0;
    if (num == 0) {
        write(1, "0", 1);
        return;
    }
    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }
    while (num > 0) {
        str[i++] = num % 10 + '0';
        num /= 10;
    }
    while (i > 0) {
        write(1, &str[--i], 1);
    }
}
int _printf(const char* const format, ...)
{
    int i;
    int x;
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
		case '%':
		    c = va_arg(args, int);
                    printchar(c);
                    count++;
                    break;
		case 'i':
		    x = va_arg(args, int);
		    print_intt(x);
		    count++;
		    break;
		case 'd':
		    x = va_arg(args, int);
                    print_intt(x);
                    count++;
                    break;




                }
            }
            if (!((format[i] == '%' || format[i - 1] == '%') && ((format[i + 1] == 's' || format[i + 1] == 'c' ) || (format[i] == 's' || format[i] == 'c' ))))

            {
                printchar(format[i]);
                count++;
            }
        }
        va_end(args);
    }
    return (count);
}
