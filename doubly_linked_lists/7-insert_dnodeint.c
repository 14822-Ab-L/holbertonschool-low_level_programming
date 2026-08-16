#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: pointer to the head of the list
 * @idx: index where the new node should be inserted
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;
	i = 0;

	while (current != NULL && i < idx)
	{
		current = current->next;
		i++;
	}

	if (current == NULL && i == idx)
		return (add_dnodeint_end(h, n));

	if (current == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = current->prev;
	new_node->next = current;

	current->prev->next = new_node;
	current->prev = new_node;

	return (new_node);
}
