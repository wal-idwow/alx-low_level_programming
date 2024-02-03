#include "hash_tables.h"

/**
* hash_table_delete - delete a hash tabble
* @ht: hash table pointer
* description: delete hash table
*/
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *curr;
	hash_node_t *tp;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];

		while (curr != NULL)
		{
			tp = curr;
			curr = curr->next;
			free(tp->key);
			free(tp->value);
			free(tp);
		}
	}
	free(ht->array);
	free(ht);
}
