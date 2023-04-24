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
	int i, x, count = 0;
	int l;
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
			    if(format[i+2] == 'd' || 'c' || 'i' || 's' )
			    {
			        printchar('%');
			        printchar(format[i+2]);
			        count++;
			        count++;
			        i = i + 3;
			    }
			    else{
			printchar('%');
				count++;
				i = i + 2;
			    }
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
					len = strllen(s);
					printstring(s, len);
					count = count + len;
					break;

				case 'i':
				case 'd':
					x = va_arg(args, int);
					print_intt(x);
					if (x < 0)
					{
					    count++;
					}
					for(l = 0; x != 0; l++)
					{
					    x = x / 10;
					}
					count = count + l;
					break;
				default:
					break;
				}
			}
			if (!((format[i] == '%' || format[i - 1] == '%')
			      && ((format[i + 1] == 's' || format[i + 1] == 'c'
				   || format[i + 1] == 'i' || format[i + 1] == 'd')
				   	|| (format[i] == 's' || format[i] == 'c'  
					    || format[i] == 'i' || format[i] == 'd'))))
			{
				printchar(format[i]);
				count++;
			}
		}
		va_end(args);
	}
	return (count);
}
