#include "lists.h"

/**
	* print_listint - prints a linke lists
	* @h: pointer to first node
	*
	* Return: size of list
*/

size_t print_listint(const listint_t *h)
{
	size_t b = 0;

	while (h)
	{
		h = h->next;
		b++;
	}
	return (b);
}
