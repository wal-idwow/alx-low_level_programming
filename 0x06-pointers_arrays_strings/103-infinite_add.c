#include "main.h"

/**
 * _strlen - computes the length of a string
 * @str: input string
 * Return: length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * reverse_string - reverses a string
 * @str: input string
 * @len: length of the string
 */
void reverse_string(char *str, int len)
{
	int start = 0;
	int end = len - 1;

	while (start < end)

	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

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

	len1 = _strlen(n1);
	len2 = _strlen(n2);

	if (size_r <= len1 || size_r <= len2)
		return (0);

	i = len1 - 1;
	j = len2 - 1;
	carry = 0;
	r[size_r] = '\0';

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		r[--size_r] = (sum % 10) + '0';

		carry = sum / 10;

		i--;
		j--;
	}

	if (carry)
		r[--size_r] = carry + '0';

	reverse_string(r + size_r, _strlen(r + size_r));

	return (r + size_r);
}

