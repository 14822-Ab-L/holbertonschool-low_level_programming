#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints char
 * @args: argument list
 *
 * Return: void
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints integer
 * @args: argument list
 *
 * Return: void
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints float
 * @args: argument list
 *
 * Return: void
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints string
 * @args: argument list
 *
 * Return: void
 */
void print_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (!s)
		s = "(nil)";

	printf("%s", s);
}

/**
 * print_all - prints anything
 * @format: list of argument types
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	printer_t functions[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};
	va_list args;
	char *sep = "";
	int i = 0;
	int j;

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;

		while (functions[j].symbol)
		{
			if (format[i] == functions[j].symbol[0])
			{
				printf("%s", sep);
				functions[j].print(args);
				sep = ", ";
			}

			j++;
		}

		i++;
	}

	va_end(args);

	printf("\n");
}
