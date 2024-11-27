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
		count = count + print_char(*pointer);
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
		count = count + print_char(va_arg(arguments, int));
	else if (specifier == 's')
		count = count + print_string(va_arg(arguments, char *));
	else if (specifier == '%')
		count = count + print_percent();
	else if ((specifier == 'i') || (specifier == 'd'))
		count = count + print_number(va_arg(arguments, int));
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
int print_char(char character)
{
	return (write(1, &character, 1));
}

/**
 * print_string - Print a string.
 * @s: The string to print.
 * Return: The number of characters printed.
 */
int print_string(char *string)
{
	int index = 0;

	if (string == NULL)
		string = "(null)";

	while (string[index] != '\0')
		index++;
	return (write(1, string, index));
}

/**
 * print_percent - Print a percent sign.
 * Return: The number of characters printed (1).
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}

/*
 * print_number - print a number.
 * @number: number to print
 * Return: the number of character printed.
 */
int print_number(int number)
{
	char digit;
	int count = 0;

	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		count++;
	}
	if (number / 10)
	{
		count = count + print_number(number/10);
	}
	digit = (number % 10) + '0';

	write(1, &digit, 1);
	count++;

	return (count);
}
