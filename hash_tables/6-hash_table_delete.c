#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table to delete
 *
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	hash_node_t *next;

	if (ht == NULL)
		return;

	i = 0;
	while (i < ht->size)
	{
		node = ht->array[i];

		while (node != NULL)
		{
			next = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}

		i++;
	}

	free(ht->array);
	free(ht);
}
