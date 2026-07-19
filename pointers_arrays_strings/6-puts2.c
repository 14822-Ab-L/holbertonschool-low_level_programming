#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @str: string to print
 */
void puts2(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;

	while (str[len] != '\0')
		len++;

	while (i < len)
	{
		_putchar(str[i]);
		i += 2;
	}

	_putchar('\n');
}
