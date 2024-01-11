#include "lists.h"
/**
* sum_dlistint - sum of all the data (n) of a dlistint_t linked list
* @head: address of pointer to current head node
* Return: int values sum
*/
int sum_dlistint(dlistint_t *head)
{
	int total = 0;

	while (head)
	{
		total += head->n;
		head = head->next;
	}
	return (total);
}
