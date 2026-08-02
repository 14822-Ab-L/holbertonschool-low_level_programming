#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints a character
 * @args: argument list
 *
 * Return: void
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an integer
 * @args: argument list
 *
 * Return: void
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: argument list
 *
 * Return: void
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: argument list
 *
 * Return: void
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(nil)";

	printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	int first = 1;
	char *separator = ", ";

	void (*functions[])(va_list) = {
		print_char,
		print_int,
		print_float,
		print_string
	};

	char types[] = {'c', 'i', 'f', 's'};

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		int j = 0;

		while (j < 4)
		{
			if (format[i] == types[j])
			{
				if (first == 0)
					printf("%s", separator);

				functions[j](args);
				first = 0;
			}
			j++;
		}

		i++;
	}

	va_end(args);

	printf("\n");
}
