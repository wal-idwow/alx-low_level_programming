#include "lists.h"

/**
	* delete_nodeint_at_index - deletes node at given index
	* @head: address of pointer to first node
	* @index: index of node to delete
	*
	* Return: 1 on success. -1 on failure
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *nd, *pr_node;
	unsigned int a = 0;

	if (!head || *head)
		return (-1);

	if (!index)
	{
		nd = *head;
		*head = (*head)->next;
		free(nd);
		return (1);
	}
	nd = *head;
	while (nd)
	{
		if (a == index)
		{
			pr_node->next = nd->next;
			free(nd);
			return (1);
		}
		a++;
		pr_node = nd;
		nd = nd->next;
	}
	return (-1);
}
