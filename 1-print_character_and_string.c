#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
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
