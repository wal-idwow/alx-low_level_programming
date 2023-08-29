#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
	* _r - reallocates memory for an array of pointer
	* to the nodes in a linked list
	* @list: the old list to append
	* @size: size of the new list (always one more than the old list)
	* @new: new node to add to the list
	*
	* Return: pointer to the new list
*/

const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **nwlst;
	size_t a;

	nwlst = malloc(size * sizeof(listint_t *));
	if (nwlst == NULL)
	{
		free(list);
		exit(98);
	}
	for (a = 0; a < size - 1; a++)
	nwlst[a] = list[a];
	nwlst[a] = new;
	free(list);
	return (nwlst);
}

/**
	* print_listint_safe - prints a listint_t linked list
	* @head: pointer to the start of the list
	*
	* Return: the number of nodes in the list
*/

size_t print_listint_safe(const listint_t *head)
{
	size_t a, num = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (a = 0; a < num; a++)
		{
			if (head == list[a])
			{
				printf("->[%p] %d\n", (void *)head, head->n);
				free(list);
				return (num);
			}
		}
		num++;
		list = _r(list, num, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (num);
}
