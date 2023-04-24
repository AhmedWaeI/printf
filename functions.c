#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * printstring - Prints a string
 * @s: List of arguments
 * @len: Buffer array to handle print
 *
 * Return: Number of chars printed
 */
int printstring(char *s, int len)
{
	write(1, s, len);
	return (len);
}

/**
 * printchar - Prints a char
 * @c: char to print
 *
 * Return: Number of chars printed
 */
int printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * strllen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
unsigned long int strllen(const char *s)
{
	unsigned long int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * print_intt - Prints an integer
 * @num: integer to print
 *
 * Return: void
 */
void print_intt(int num)
{
	char str[10];
	int i = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return;
	}

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}

	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}

	while (i > 0)
	{
		write(1, &str[--i], 1);
	}
}
/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
unsigned int printbinary(int num)
{
    int i;
    int j;
    int r;
    int *s;

    s = malloc(sizeof(int) * (32));
    for(i = 0; num != 0 ; i++)
    {
        s[i]= num % 2;
        num = num / 2;
        
    }
    r = i;
    for(j = i - 1; j >= 0; j--)
    {
        print_intt(s[j]);
    }
    return r;
}
