#include "lists.h"
#include <stdlib.h>

/**
	* find_listint_loop_fl - finds a loop in a linked list
	* @head: linked list to  search
	* Return: address of nodes of node where loop starts/returns, NULL if no loop
*/

listint_t *find_listint_loop_fl(listint_t *head)
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

/**
	* free_listint_safe - frees a listint list, even if it has a loop
	* @h: head of list
	*
	* Return: number of nodes freed
*/

size_t free_listint_safe(listint_t **h)
{
	listint_t *sv, *loopnd;
	size_t ln;
	int lp = 1;

	if (h == NULL || *h == NULL)
		return (0);

	loopnd = find_listint_loop_fl(*h);
	for (ln = 0; (*h != loopnd || lp) && *h != NULL; *h = sv)
	{
		ln++;
		sv = (*h)->next;
		if (*h == loopnd && lp)
		{
			if (loopnd == loopnd->next)
			{
				free(*h);
				break;
			}
			ln++;
			sv = sv->next;
			free((*h)->next);
			lp = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (ln);
}
