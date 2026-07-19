#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to check
 * @accept: characters to accept
 *
 * Return: number of bytes in the prefix substring
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int i;
	int found;

	count = 0;

	while (s[count] != '\0')
	{
		found = 0;
		i = 0;

		while (accept[i] != '\0')
		{
			if (s[count] == accept[i])
			{
				found = 1;
			}

			i++;
		}

		if (found == 0)
		{
			break;
		}

		count++;
	}

	return (count);
}
