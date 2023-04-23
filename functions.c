#include "main.h"
#include <unistd.h>
#include <stdarg.h>
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
    write(STDOUT_FILENO, s, len);
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
    write(STDOUT_FILENO, &c, 1);
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
unsigned long int strlen(char* s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    return (i);
}
