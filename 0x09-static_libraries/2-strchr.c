#include "main.h"

/**
	* *_strchr -  locates a character in a string
	* @s: pointer to put the constant
	* @c: constant
	* Return: pointer to s
*/

char *_strchr(char *s, char c)
{
	int ar;

	for (ar = 0; s[ar] >= '\0' ; ar++)
	{
		if (s[ar] == c)
		{
			return (s + ar);
		}
	}
	return ('\0');
}
