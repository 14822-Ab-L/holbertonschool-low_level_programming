#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer value
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int result;
	int digit;

	i = 0;
	sign = 1;
	result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;

		else if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				digit = s[i] - '0';
				result = result * 10 - digit;
				i++;
			}

			if (sign == 1)
				return (-result);

			return (result);
		}

		i++;
	}

	return (0);
}
