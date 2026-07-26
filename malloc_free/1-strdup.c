#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space
 * containing a copy of the string
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, or NULL
 */
char *_strdup(char *str)
{
	char *copy;
	int length;
	int i;

	if (str == NULL)
	{
		return (NULL);
	}

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	copy = malloc((length + 1) * sizeof(char));

	if (copy == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i <= length)
	{
		copy[i] = str[i];
		i++;
	}

	return (copy);
}
