#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase
 *
 * Return: Always end with the value 0
 */

int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		putchar(letter);
	}

	putchar('\n');

	return (0);
}
