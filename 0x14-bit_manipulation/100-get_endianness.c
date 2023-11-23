#include "main.h"

/**
	* get_endianness - returns the endianness of the system
	* Return: 0 if big endian, 1 if little
*/
int get_endianness(void)
{
	unsigned int test_value = 1;
	unsigned char *byte_ptr = (unsigned char *)&test_value;

	/* If the first byte (lowest address) is non-zero,*/
	/* the system is little-endian */
	return (*byte_ptr != 0);
}

