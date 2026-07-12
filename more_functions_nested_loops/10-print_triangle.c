#include "main.h"

/**
 * print_triangle - prints a triangle using #
 *
 * @size: size of the triangle
 *
 * Return: Nothing
 */

void print_triangle(int size)
{
	int row;
	int space;
	int hash;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		for (space = size - row; space > 0; space--)
		{
			_putchar(' ');
		}

		for (hash = 0; hash < row; hash++)
		{
			_putchar('#');
		}

		_putchar('\n');
	}
}
