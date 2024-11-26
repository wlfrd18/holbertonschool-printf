#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produce output according to a format.
 * @format: string to print.
 * @...: arguments.
 * Return: number of characters printed
 *	   excluding the null byte of the end.
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int count = 0;
	const char *pointer = format;

	va_start(arguments, format);

	while (*pointer != '\0')
	{
		if ( *pointer == '%')
		{
			pointer++;
			if (*pointer == 'c')
			{
				char c = va_arg(arguments, int);
				write(1, &c, 1);
				count++;
			}
			else if (*pointer == 's')
			{
				char *string = va_arg(arguments, char *);
				if (string == NULL)
				{
					string = NULL;
				}
				while (*string != 0)
				{
					write(1, string, 1);
					string++;
					count++;
				}
			}
			else if (*pointer == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1, "%", 1);
				write(1, pointer, 1);
				count += 2;
			}
		}
		else
		{
			write(1, pointer, 1);
			count++;
		}
		pointer++;
	}
	va_end(arguments);
	return (count);
}
