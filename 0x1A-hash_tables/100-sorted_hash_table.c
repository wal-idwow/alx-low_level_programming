#include "hash_tables.h"
/**
 * shash_table_create -creates a sorted hash table.
 * @size: size of new sorted hash table.
 * Return: on failure > NULL.
 *         on success > a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *htable;
	unsigned long int i;

	htable = malloc(sizeof(shash_table_t));
	if (htable == NULL)
		return (NULL);

	htable->size = size;
	htable->array = malloc(sizeof(shash_node_t *) * size);
	if (htable->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		htable->array[i] = NULL;
	htable->shead = NULL;
	htable->stail = NULL;

	return (htable);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: sorted hash table pointer.
 * @key: The key to be indexed.
 * @value: The value associated with key.
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *nw, *tp;
	char *copy_v;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	copy_v = strdup(value);
	if (copy_v == NULL)
		return (0);

	i = key_index((const unsigned char *)key, ht->size);
	tp = ht->shead;
	while (tp)
	{
		if (strcmp(tp->key, key) == 0)
		{
			free(tp->value);
			tp->value = copy_v;
			return (1);
		}
		tp = tp->snext;
	}

	nw = malloc(sizeof(shash_node_t));
	if (nw == NULL)
	{
		free(copy_v);
		return (0);
	}
	nw->key = strdup(key);
	if (nw->key == NULL)
	{
		free(copy_v);
		free(nw);
		return (0);
	}
	nw->value = copy_v;
	nw->next = ht->array[i];
	ht->array[i] = nw;

	if (ht->shead == NULL)
	{
		nw->sprev = NULL;
		nw->snext = NULL;
		ht->shead = nw;
		ht->stail = nw;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		nw->sprev = NULL;
		nw->snext = ht->shead;
		ht->shead->sprev = nw;
		ht->shead = nw;
	}
	else
	{
		tp = ht->shead;
		while (tp->snext != NULL && strcmp(tp->snext->key, key) < 0)
			tp = tp->snext;
		nw->sprev = tp;
		nw->snext = tp->snext;
		if (tp->snext == NULL)
			ht->stail = nw;
		else
			tp->snext->sprev = nw;
		tp->snext = nw;
	}
	return (1);
}

/**
 * shash_table_get - retrieve value associated with
 *                   a key in a sorted hash table.
 * @ht: sorted hash table pointer .
 * @key: key to get value.
 * Return: on success > value associated with key int hash table
*          on failure > NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *nd;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	i = key_index((const unsigned char *)key, ht->size);
	if (i >= ht->size)
		return (NULL);

	nd = ht->shead;
	while (nd != NULL && strcmp(nd->key, key) != 0)
		nd = nd->snext;

	return ((nd == NULL) ? NULL : nd->value);
}

/**
 * shash_table_print - prints a sorted hash table.
 * @ht: sorted hash table pointer.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *nd;

	if (ht == NULL)
		return;

	nd = ht->shead;
	printf("{");
	while (nd != NULL)
	{
		printf("'%s': '%s'", nd->key, nd->value);
		nd = nd->snext;
		if (nd != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order.
 * @ht: sorted hash table to print pointer.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *nd;

	if (ht == NULL)
		return;

	nd = ht->stail;
	printf("{");
	while (nd != NULL)
	{
		printf("'%s': '%s'", nd->key, nd->value);
		nd = nd->sprev;
		if (nd != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - delete a sorted hash table.
 * @ht: sorted hash table pointer.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *nd, *tp;

	if (ht == NULL)
		return;

	nd = ht->shead;
	while (nd)
	{
		tp = nd->snext;
		free(nd->key);
		free(nd->value);
		free(nd);
		nd = tp;
	}

	free(head->array);
	free(head);
}
