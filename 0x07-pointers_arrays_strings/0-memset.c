#include "main.h"

/**
	* *_memset -  fills memory with a constant byte
	* @s: pointer to pu the constant
	* @b: constant
	* @n: max bytes to use
	* Return: pointer s
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int ar;

	for (ar = 0; n > 0; ar++, n--)
	{
		s[ar] = b;
	}
	return (s);

}
