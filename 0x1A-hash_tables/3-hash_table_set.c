#include "hash_tables.h"
/**
* hash_table_set - adds an element to the hash table.
* @ht: hash table
* @key: key to be indexed
* @value: value to be set in the hash table
* Return: 1 on sucess, 0 on failure
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	hash_node_t  *curr, *node;

	if (strcmp(key, "") == 0 || ht == NULL || key == NULL)
		return (0);
	i = key_index((const unsigned char *)key, ht->size);
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		free(node);
		return (0);
	}
	node->key = strdup((char *)key);
	node->value = strdup((char *)value);
	node->next = NULL;
	if (ht->array[i] == NULL)
		ht->array[i] = node;
	else
	{
		curr = ht->array[i];
		if (strcmp(curr->key, key) == 0)
		{
			node->next = curr->next;
			ht->array[i] = node;
			free(curr);
			return (1);
		}
		while (curr->next != NULL && strcmp(curr->next->key, key) != 0)
		{curr = curr->next;
		}
		if (strcmp(curr->key, key) == 0)
		{
			node->next = curr->next->next;
			free(curr->next);
			curr->next = node;
		} else
		{
			node->next = ht->array[i];
			ht->array[i] = node; }
	}
	return (1); }
