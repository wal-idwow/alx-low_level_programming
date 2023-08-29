#include "lists.h"

/**
	* free_listint2 - frees a list of ints
	* @head: address of pointer to first node
	*
	* Return: void
*/

void free_listint2(listint_t **head)
{
	listint_t *node, *tp;

	if (!head)
		return;

	node = *head;
	while (node)
	{
		tp = node;
		node = node->next;
		free(tp);
	}
	*head = NULL;
}
