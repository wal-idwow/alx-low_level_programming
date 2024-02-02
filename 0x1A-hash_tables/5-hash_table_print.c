#include "hash_tables.h"

/**
* hash_table_print -  prints a hash table.
* @ht: hash table pointer
* Description: print the key - value in order
*/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *n;
	unsigned char symb = 0;
	unsigned long int i;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (symb == 1)
				printf(", ");

			n = ht->array[i];
			while (n != NULL)
			{
				printf("'%s': '%s'", n->key, n->value);
				n = n->next;
				if (n != NULL)
					printf(", ");
			}
			symb = 1;
		}
	}
	printf("}\n");
}
