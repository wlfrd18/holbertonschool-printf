#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

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
		write(1, "-", 1);
		number = -number;
		count++;
	}
	if (number / 10)
	{
		count = count + print_number(number / 10);
	}
	digit = (number % 10) + '0';

	write(1, &digit, 1);
	count++;

	return (count);
}
