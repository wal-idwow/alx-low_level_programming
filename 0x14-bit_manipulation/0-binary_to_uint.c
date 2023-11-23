#include "main.h"

/**
	* binary_to_uint - convert a binary number to an unsigned int
	* @b: the binary number as a string
	* Return: unsigned int form of b
*/

unsigned int binary_to_uint(const char *b)
{
	/* Initialize the result to 0.*/
	unsigned int result = 0;

	/* Check if the input string is NULL.*/
	if (!b)
	{
		return (0);
	}

	/* Iterate through each character in the string.*/
	while (*b)
	{
		if (*b != '0' && *b != '1')
		{
			return (0);
		}
		/*Shift result to the left by 1 = * by 2 (-'-)*/
		/*add value of the current binary digit ('0' or '1').*/
		result = (result << 1) | (*b++ - '0');
	}
	return (result);
}

