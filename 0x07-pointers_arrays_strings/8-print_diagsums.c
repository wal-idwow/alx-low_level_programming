#include "main.h"
#include "stdio.h"

/**
	* print_diagsums - prints the sum of the two diagonals
	*			of a square matrix of integers
	* @a: 2d array of int types
	* @size: size of array (square)
*/

void print_diagsums(int *a, int size)
{
	int ar, s1 = 0, s2 = 0;

	for (ar = 0; ar < size; ar++)
	{
		s1 += a[ar];
		s2 += a[size - ar - 1];
		a += size;
	}
	printf("%d, ", s1);
	printf("%d\n", s2);
}
