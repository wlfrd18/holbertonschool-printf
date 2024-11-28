#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produce output according to a format.
 * @format: String to print.
 * @...: Arguments.
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
 	va_list arguments;
 	int count = 0;
	const char *pointer = format;

	va_start(arguments, format);

	while (*pointer != '\0')
	{
	if (*pointer == '%')
	{
		pointer++;
		count = count + handle_specifiers(*pointer, arguments);
	}
	else
	{
		count = count + print_character(*pointer);
	}
	pointer++;
	}
	va_end(arguments);
	return (count);
}

/**
 * handle_specifiers - Handle the format specifiers.
 * @specifier: The format specifier.
 * @arguments: The arguments list.
 * Return: The number of characters printed for the specifier.
 */
int handle_specifiers(char specifier, va_list arguments)
{
	int count = 0;

	if (specifier == 'c')
		count = count + print_character(va_arg(arguments, int));
	else if (specifier == 's')
		count = count + print_string(va_arg(arguments, char *));
	else if (specifier == '%')
		count = count + print_character('%');
	else if ((specifier == 'i') || (specifier == 'd'))
		count = count + print_number(va_arg(arguments, int));
	else
	{
	count += print_character('%');
	count += print_character(specifier);
	}

 	return (count);
}

