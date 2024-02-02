#include "hash_tables.h"
/**
* key_index - function that give the index of a key.
* @key: key to be indexed
* @size: hash table size
* Return: integer
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int value;

	value = hash_djb2(key) % size;
	return (value);
}
