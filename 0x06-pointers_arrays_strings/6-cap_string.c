#include "main.h"

/**
	* isLower - determine whether ascii is lowercase
	* @c: character
	* Return: 1 if true, 0 if false
*/

int isLower(char c)
{
	return (c >= 97 && c <= 122);
}

/**
	* isDelimter - determine whether ascii is a delimiter
	* @c: character
	* Return: 1 if true, 0 if false
*/

int isDelimiter(char c)
{
	int a;
	char delimiter[] = " \t\n,.!?\"(){}";

	for (a = 0; a < 12; a++)
		if (c == delimiter[a])
			return (1);
	return (0);
}

/**
	* cap_string - capitalizes all words of a string
	* @s: input string
	* Return: string with capitalized words
*/

char *cap_string(char *s)
{
	char *ptr = s;
	int foundDelimit = 1;

	while (*s)
	{
		if (isDelimiter(*s))
			foundDelimit = 1;
		else if (isLower(*s) && foundDelimit)
		{
			*s -= 32;
			foundDelimit = 0;
		}
		else
			foundDelimit = 0;
		s++;
	}
	return (ptr);
}
