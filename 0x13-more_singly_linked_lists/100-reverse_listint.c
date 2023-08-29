#include "lists.h"

/**
	* reverse_lisstint - reverses an int list
	* @head: address of pointer to first node
	*
	* Return: address of head
*/

listint_t *reverse_listint(listint_t **head)
{
	listint_t *nd = NULL, *nt = NULL;

	if (!head || !*head)
		return (NULL);

	nd = *head;
	*head = NULL;
	while (nd)
	{
		nt = nd->next;
		nd->next = *head;
		*head = nd;
		nd = nt;
	}
	return (*head);
}
