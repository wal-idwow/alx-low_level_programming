#include "main.h"

/**
	* flip_bits - return number of bits that would need to be flipped to
	*			transform one number to another
	* @n: 1st number
	* @m: 2nd number
	* Return: number of bits to flip to convert numbers
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xval = n ^ m;
	unsigned int ct = 0;

	while (xval)
	{
		if (xval & 1ul)
			ct++;
		xval = xval >> 1;
	}
	return (ct);
}
