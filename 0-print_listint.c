#include "lists.h"
#include <stdio.h>


/**
	* print_listint - prints a linke lists
	* @h: pointer to first node
	*
	* Return: size of list
*/

size_t print_listint(const listint_t *h)
{
	size_t a = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		a++;
	}
	return (a);
}
