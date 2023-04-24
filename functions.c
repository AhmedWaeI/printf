#include "main.h"
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
