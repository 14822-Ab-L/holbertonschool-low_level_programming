#include <stdio.h>

/**
 * main - Prints hexadecimal numbers in lowercase
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	i = '0';
	while (i <= '9')
	{
		putchar(i);
		i++;
	}

	i = 'a';
	while (i <= 'f')
	{
		putchar(i);
		i++;
	}

	putchar('\n');

	return (0);
}      
