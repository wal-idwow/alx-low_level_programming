#include "lists.h"

/**
	* sum_listint - returns sum of all data
	* @head: pointer to first node
	*
	* Retrun: all
*/

int sum_listint(listint_t *head)
{
	int all = 0;

	while (head)
	{
		all += head->n;
		head = head->next;
	}
	return (all);
       
}
