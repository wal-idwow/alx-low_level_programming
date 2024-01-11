#include "lists.h"
/**
* get_dnodeint_at_index - the nth node of a dlistint_t linked list.
* @head: address of pointer to current head node
* @index: element index
* Return: element by index
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int n;

	for (n = 0; n < index && head->next; n++)
	{
		head = head->next;
	}
	if (n < index)
		return (NULL);
	return (head);
}
