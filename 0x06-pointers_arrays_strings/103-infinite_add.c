#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: result buffer
 * @size_r: buffer size
 *
 * Return: Pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, carry, sum, i, j;

	len1 = len2 = carry = 0;

	/* Calculate the length of both numbers */
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	/* Ensure the buffer can hold the result */
	if (size_r <= len1 || size_r <= len2)
		return (0);

	/* Initialize indices to the last digit of both numbers and result buffer */
	i = len1 - 1;
	j = len2 - 1;
	r[size_r] = '\0'; /* Null-terminate the result buffer */

	/* Traverse from right to left and add digits */
	while (i >= 0 || j >= 0 || carry)
	{
		/* Calculate the sum of the current digits and the carry */
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		/* Store the last digit of the sum in the result buffer */
		r[--size_r] = (sum % 10) + '0';

		/* Update carry for the next iteration */
		carry = sum / 10;

		/* Move to the next digit of both numbers */
		i--;
		j--;
	}

	/* If the result has a carry, add it to the buffer */
	if (carry)
		r[--size_r] = carry + '0';

	/* Move the result pointer to the beginning of the actual result */
	return (r + size_r);
}

