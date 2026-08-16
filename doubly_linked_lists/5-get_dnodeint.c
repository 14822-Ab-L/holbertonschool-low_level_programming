#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a doubly linked list
 * @head: pointer to the head of the list
 * @index: index of the node to return
 *
 * Return: pointer to the node at index, or NULL if it does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;

	while (head != NULL && i < index)
	{
		head = head->next;
		i++;
	}

	return (head);
}
