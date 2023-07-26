#include "main.h"

/**
	* _strcmp - compare two strings
	* @s1: string 1
	* @s2: string 2
	* Return: 1 if true, 0 if false
*/

int _strcmp(char *s1, char *s2)
{
	int comp = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			comp = ((int)*s1 - 48) - ((int)*s2 - 48);
			break;
		}
		s1++;
		s2++;
	}
	return (comp);
}
