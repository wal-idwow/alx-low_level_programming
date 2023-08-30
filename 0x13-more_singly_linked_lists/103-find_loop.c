#include "lists.h"
#include <stdlib.h>

/**
	* find_listint_loop - finds a loop in a linked list
	* @head: linked list to search
	* Return: address of node where loop starts/returns, NULL if no loop
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *pt, *ed;

	if (head == NULL)
		return (NULL);
	for (ed = head->next; ed != NULL; ed = ed->next)
	{
		if (ed == ed->next)
			return (ed);
		for (pt = head; pt != ed; pt = pt->next)
			if (pt == ed->next)
				return (ed->next);
	}
	return (NULL);
}
