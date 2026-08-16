#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table to print
 *
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first;

	if (ht == NULL)
		return;

	printf("{");
	first = 1;
	i = 0;

	while (i < ht->size)
	{
		node = ht->array[i];

		while (node != NULL)
		{
			if (first == 0)
				printf(", ");

			printf("'%s': '%s'", node->key, node->value);
			first = 0;
			node = node->next;
		}

		i++;
	}

	printf("}\n");
}
