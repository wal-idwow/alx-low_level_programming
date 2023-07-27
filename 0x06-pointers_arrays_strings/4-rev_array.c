#include "main.h"

/**
	*reverse_array - reverse the content of an array of an integer
	* @a: an array of integers
	* @n: the number of elements to swap
*/

void reverse_array(int *a, int n)
{
	int m, b, j;

	for (m = 0, b = (n - 1); m < b; m++, b--)
	{
		j = a[m];
		a[m] = a[b];
		a[b] = j;
	}

}
