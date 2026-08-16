#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data in a list
 * @head: pointer to the head of the list
 *
 * Return: sum of all the node data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;

	while (head != NULL)
	{
		sum = sum + head->n;
		head = head->next;
	}

	return (sum);
}
