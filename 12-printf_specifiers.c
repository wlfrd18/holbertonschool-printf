#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_character - Print a single character.
 * @c: The character to print.
 * Return: The number of characters printed (1).
 */
int print_character(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Print a string.
 * @string: The string to print.
 * Return: The number of characters printed.
 */
int print_string(char *string)
{
	int index = 0;

	if (string == NULL)
		string = "(null)";

	while (string[index] != '\0')
		index++;
	return (write(1, string, (index + 1)));
}

/**
 * print_percent - Print a percent sign.
 * Return: The number of characters printed (1).
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * print_number - Print an integer to standard output.
 * @number: number to print.
 * Return: the number of character printed.
 */
int print_number(int number)
{
	char digit;
	int count = 0;

	if (number < 0)
	{
		count += print_character('-');
		number = -number;
	}
	if (number / 10)
	{
		count = count + print_number(number / 10);
	}
	digit = (number % 10) + '0';

	count = count + print_character(digit);

	return (count);
}
