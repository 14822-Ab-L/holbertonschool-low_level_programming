#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array and initializes it to zero
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to allocated memory, or NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *memory;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	memory = malloc(nmemb * size);

	if (memory == NULL)
	{
		return (NULL);
	}

	i = 0;

	while (i < (nmemb * size))
	{
		((char *)memory)[i] = 0;
		i++;
	}

	return (memory);
}
