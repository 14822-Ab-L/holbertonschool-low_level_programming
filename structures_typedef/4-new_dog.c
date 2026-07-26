#include "dog.h"
#include <stdlib.h>

/**
 * copy_string - creates a copy of a string
 * @str: string to copy
 *
 * Return: pointer to copied string, or NULL
 */
char *copy_string(char *str)
{
	char *copy;
	unsigned int len;
	unsigned int i;

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	copy = malloc(sizeof(char) * (len + 1));

	if (copy == NULL)
	{
		return (NULL);
	}

	i = 0;

	while (i <= len)
	{
		copy[i] = str[i];
		i++;
	}

	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to new dog, or NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));

	if (dog == NULL)
	{
		return (NULL);
	}

	dog->name = copy_string(name);

	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = copy_string(owner);

	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	dog->age = age;

	return (dog);
}
