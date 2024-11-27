#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/*
 * print_number - print a number.
 * @number: number to print
 * Return: the number of character printed.
 */
int print_number(int n)
{
	char digit;
	int count = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n / 10)
	{
		count = count + print_number(n/10);
	}
	digit = (n % 10) + '0';

	write(1, &digit, 1);
	count++;

	return (count);
}
