#include "lists.h"

/**
	* add_node_end - adds a node to the end of the list
	* @head: address of pointer to head node
	* @str:: str field of node
	*
	* Return: size of list
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *node = *head;
	unsigned int len;

	if (!head || !new_node)
		return (NULL);
	if (str)
	{
		while (str[len])
		len++;
		new_node->str = strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
		new_node->len = len;
	}
	if (node)
	{
		while (node->next)
		node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
		return (new_node);
}
