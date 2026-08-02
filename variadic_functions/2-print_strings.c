#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings separated by a separator
 * @separator: string between strings
 * @n: number of strings
 *
 * Return: Nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *string;

	va_start(args, n);

	i = 0;

	while (i < n)
	{
		string = va_arg(args, char *);

		if (string == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", string);
		}

		if (i < n - 1 && separator != NULL)
		{
			printf("%s", separator);
		}

		i++;
	}

	va_end(args);

	printf("\n");
}
