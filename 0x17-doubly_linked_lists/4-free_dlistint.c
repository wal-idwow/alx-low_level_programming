#include "lists.h"
/**
* free_dlistint - function that frees a dlistint_t list.
* @head: address of pointer to current head node
* Return: void
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}

}
