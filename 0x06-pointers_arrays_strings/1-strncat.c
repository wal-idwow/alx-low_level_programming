#include "main.h"

/**
	* _strcat - fonction that concatenates two strings
	* @dest: poniters to destination input
	* @src: pointer to source input
	* @n: most number of bytes from &src
	* Return: &dest
*/

char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	a = 0;

	while (dest[a])
		a++;

	for (b = 0; b < n && src[b] != '\0'; b++)
		dest[a + b] = src[b];

	dest[a + b] = '\0';

	return (dest);
}
