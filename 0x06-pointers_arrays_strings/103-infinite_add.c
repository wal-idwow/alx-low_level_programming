#include "main.h"

/**
 * reverse_string - Reverses a string
 * @str: The string to be reversed
 */
void reverse_string(char *str)
{

	int length = 0;
	int i, j;
	char temp;

	while (str[length])
		length++;

	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

/**
 * infinite_add - Adds two numbers represented as strings
 * @n1: First number as a string
 * @n2: Second number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 * Return: Pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0, carry = 0;

	while (n1[i])
		i++;
	while (n2[j])
		j++;

	if (i >= size_r - 1 || j >= size_r - 1)
	return (0);

	r[size_r - 1] = '\0';
	i--;
	j--;

	while (i >= 0 || j >= 0 || carry)
	{
		int digit1 = (i >= 0) ? n1[i] - '0' : 0;
		int digit2 = (j >= 0) ? n2[j] - '0' : 0;
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		r[k++] = (sum % 10) + '0';
		i--;
		j--;
	}

	if (k == size_r - 1)
	return (0);

	r[k] = '\0';
	reverse_string(r);

	return r;
}

