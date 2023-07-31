#include "main.h"

/**
	* *_memcpy - copies memory area
	* @dest: memory area
	* @src: source
	* @n: length of src to be copied
	* return: the pointer to dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int ar;

	for (ar = 0; ar < n; ar++)
	{
		dest[ar] = src[ar];
	}
	return (dest);
}
