#include "lists.h"
#include <stddef.h>

/**
	* listint_len - prints a linked lists
	* @h: pointer to first node
	*
	* Return: size of list
*/

size_t listint_len(const listint_t *h)
{
	size_t b = 0;

	while (h != NULL)
	{
		h = h->next;
		b++;
	}
	return (b);
}
