#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
	* print_list - prints a linked lists
	* @h: pointer to first node
	*
	* Return: size of list
*/

size_t print_list(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		s++;
	}
	return (s);
}
