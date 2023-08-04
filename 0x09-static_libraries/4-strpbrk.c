#include "main.h"

/**
	* *_strpbrk - searches a string for any of a set of bytes
	* @s: string
	* @accept: string to match
	* Return: pointer to the byte in s that matches one of the
	* bytes in accept or NULL if no such bytes is found
*/

char *_strpbrk(char *s, char *accept)
{
	int ar, br;
	char *p;

	ar = 0;
	while (s[ar] != '\0')
	{
		br = 0;
		while (accept[br] != '\0')
		{
			if (accept[br] == s[ar])
			{
				p = &s[ar];
				return (p);
			}
			br++;
		}
		ar++;

	}
	return (0);
}
