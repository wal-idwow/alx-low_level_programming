#include "main.h"

/**
	* flip_bits - return number of bits that would need to be flipped to
	*		transform one number to another
	* @n: 1st number
	* @m: 2nd number
	* Return: number of bits to flip to convert numbers
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int flip_count = 0;

	/* Count the set bits using Brian Kernighan's algorithm */
	while (xor_result)
	{
		xor_result &= (xor_result - 1);
		flip_count++;
	}
	return (flip_count);
}

