#include "function_pointers.h"

/**
	* int_index - searches for integer
	* @array: int array
	* @size: array size
	* @cmp: compare function
	* Return: integr index
*/

int int_index(int *array, int size, int (*cmp)(int))
{
	int e = 0;

	if (array && size && cmp)
		while (e < size)
		{
			if (cmp(array[e]))
				return (e);
			e++;
		}
	return (-1);
}
