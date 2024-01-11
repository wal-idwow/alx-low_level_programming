#include "lists.h"
/**
* insert_dnodeint_at_index - inserts a new node at a given position.
* @h: pointer to the head of the dlistint_t list
* @idx: position to insert to the node
* @n: integer for the new node to contain
* Return: NULL if it faile - new node adress if success
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h, *nw;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		if (temp == NULL)
			return (NULL);
		temp = temp->next;
	}
	if (temp == NULL || temp->next == NULL)
		return (add_dnodeint_end(h, n));

	nw = malloc(sizeof(dlistint_t));
	if (nw == NULL)
		return (NULL);

	nw->n = n;
	nw->prev = temp;
	nw->next = temp->next;
	temp->next->prev = nw;
	temp->next = nw;

	return (nw);
}
