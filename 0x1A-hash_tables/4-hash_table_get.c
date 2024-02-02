#include "hash_tables.h"

/**
* hash_table_get - retrieves a value associated with a key.
* @key: key to value
* @ht: hash table pointer
* Return: on success > value associated with key int hash table
*          on failure > NULL
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i;

	hash_node_t *n;


	if (key == NULL || ht == NULL || *key == '\0')
		return (NULL);

	i = key_index((const unsigned char *)key, ht->size);


	if (i >= ht->size)
		return (NULL);

	n = ht->array[i];
	while (n && strcmp(n->key, key) != 0)
		n = n->next;

	return ((n == NULL) ? NULL : n->value);
}
