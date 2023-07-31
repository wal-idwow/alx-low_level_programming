#include "main.h"

/**
	* _strspn -  gets the length of a prefix substring
	* @s: string
	* @accept: bytes
	* Return: unsigned int
*/

unsigned int _strspn(char *s, char *accept)
{
	unsigned int ar, br;

	for (ar = 0; s[ar] != '\0'; ar++)
	{
		for (br = 0; accept[br] != s[ar]; br++)
		{
			if (accept[br] == '\0')
				return (ar);
		}
	}
	return (ar);
}
