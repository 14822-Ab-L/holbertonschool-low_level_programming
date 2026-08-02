#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array to search
 * @size: size of array
 * @cmp: function used to compare values
 *
 * Return: index of matching element, or -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
	{
		return (-1);
	}

	i = 0;

	while (i < size)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}

		i++;
	}

	return (-1);
}
