#include "main.h"

/**
	* set_bit - sets the bit at the index
	* @n: pointer to number to index
	* @index: bit to set
	* Return: 1 if successful, -1 on error
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(*n) * 8)
		return (-1);

	*n |= (1L << index);
	return (1);
}

