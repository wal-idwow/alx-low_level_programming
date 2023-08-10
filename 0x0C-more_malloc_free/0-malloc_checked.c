#include <stdlib.h>
#include "main.h"

/**
	* *malloc_checked - allocates memory using malloc and exit if failed
	* @b: int
	* Return: pointer to the array initialized ou NULL
*/

void *malloc_checked(unsigned int b)
{
	int *n = malloc(b);

	if (n == 0)
		exit(98);

	return (n);
}
