#include "main.h"

/**
	* get_endianness - returns the endianness of the system
	* Return: 0 if big endian, 1 if little
*/

int get_endianness(void)
{
	unsigned long int a = 1;
		return (*(char *)&a);
}
