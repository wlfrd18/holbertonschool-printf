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
		count += handle_specifiers(*pointer, arguments);
	}
	else
	{
		count += print_char(*pointer);
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
		count += print_char(va_arg(arguments, int));
	else if (specifier == 's')
		count += print_string(va_arg(arguments, char *));
	else if (specifier == '%')
		count += print_percent();
	else
	{
	count += print_char('%');
	count += print_char(specifier);
	}

	return (count);
}

/**
 * print_char - Print a single character.
 * @c: The character to print.
 * Return: The number of characters printed (1).
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Print a string.
 * @s: The string to print.
 * Return: The number of characters printed.
 */
int print_string(char *s)
{
	int len = 0;

	if (s == NULL)
		s = NULL;

	while (s[len] != '\0')
		len++;
	return (write(1, s, len));
}

/**
 * print_percent - Print a percent sign.
 * Return: The number of characters printed (1).
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}
