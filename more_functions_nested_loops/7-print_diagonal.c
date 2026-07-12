#include "main.h"

/**
 * print_diagonal - draws a diagonal line using backslash
 *
 * @n: number of times the backslash character is printed
 *
 * Return: Nothing
 */
void print_diagonal(int n)
{
	int i;
	int space;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
	{
		for (space = 0; space < i; space++)
		{
			_putchar(' ');
		}

		_putchar('\\');
		_putchar('\n');
	}
}
