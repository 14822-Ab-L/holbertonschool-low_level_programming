#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to capitalize
 *
 * Return: pointer to modified string
 */
char *cap_string(char *str)
{
	int i;
	int j;
	int separator;
	char separators[] = " \t\n,;.!?\"(){}";

	i = 0;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= ('a' - 'A');

	while (str[i] != '\0')
	{
		separator = 0;
		j = 0;

		while (separators[j] != '\0')
		{
			if (str[i] == separators[j])
				separator = 1;

			j++;
		}

		if (separator && str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] -= ('a' - 'A');

		i++;
	}

	return (str);
}
