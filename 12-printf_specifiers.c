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
	{
		index++;
	}
	return (write(1, string, index));
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
	unsigned int abs_number;

	if (number < 0)
	{
		count += print_character('-');
		abs_number = -number;
	}
	else
	{
		abs_number = number;
	}
	if (abs_number / 10)
	{
		count = count + print_number(abs_number / 10);
	}
	digit = (abs_number % 10) + '0';

	count = count + print_character(digit);

	return (count);
}
