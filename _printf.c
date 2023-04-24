#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
unsigned long int _strlen(const char *s)
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

/**
 * _printf - Printf function
 * @format: format string
 *
 * Return: Number of printed chars
 */
int _printf(const char *format, ...)
{
	int i, x, count = 0;
	char c, *s;
	int len;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	if (format)
	{
		for (i = 0; format && format[i] != '\0'; i++)
		{
			if (format[i] == '%' && format[i + 1] == '%')
			{
				printchar('%');
				count++;
				i = i + 2;
			}
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
					len = _strlen(s);
					printstring(s, len);
					count = count + len;
					break;

				case 'i':
				case 'd':
					x = va_arg(args, int);
					print_intt(x);
					count++;
					break;
					
				}
			}
			else if (!((format[i] == '%' || format[i - 1] == '%') &&
           ((format[i + 1] == 's' || format[i + 1] == 'c' ||
             format[i + 1] == 'i' || format[i + 1] == 'd') ||
            (format[i] == 's' || format[i] == 'c' ||
             format[i] == 'i' || format[i] == 'd'))))

			{
				printchar(format[i]);
				count++;
			}
		}
		va_end(args);
	}
	return (count);
}
