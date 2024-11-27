#ifndef MAIN_H_
#define MAIN_H_
#include <stddef.h>

/*
 * File: main.h
 * Auth: Brice Kanga and Wilfried Guele.
 * Desc: Header file containing prototypes for all functions
 *       used in our _printf function.
 */

int _printf(const char *format, ...);
int handle_specifiers(char specifier, va_list arguments);
int print_char(char c);
int print_string(char *s);
int print_percent(void);
int print_number(int n);
#endif
