#include "main.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
	* wrdcnt - counts the number of words in a string
	* @s: string to count
	* Return: int of number of words
*/

int wrdcnt(char *s)
{
	 int i, n = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] != ' ' && s[i + 1] != '\0')
				n++;
		}
		else if (i == 0)
		{
			n++;
		}
	}
	return (n);
}
/**
	* allocate_words - allocates memory for words in the string
	* @str: input string
	* @n: number of words
	* Return: pointer to an array of strings
*/
char **allocate_words(char *str, int n)
{
	int i, j, l, wc = 0;
	char **w;

	w = (char **)malloc((n + 1) * sizeof(char *));
	if (w == NULL)
	return (NULL);

	w[n] = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
			;

			w[wc] = (char *)malloc((j + 1) * sizeof(char));
			if (w[wc] == NULL)
			{
				for (l = 0; l < wc; l++)
					free(w[l]);
				free(w);
				return (NULL);
			}

			for (l = 0; l < j; l++)
				w[wc][l] = str[i + l];
			w[wc][l] = '\0';
			wc++;
			i += j;
		}
		else
		{
		i++;
		}
	}
	return (w);
}

/**
	* strtow - splits a string into words
	* @str: string to split	* Return: pointer to an array of string
	* Return: pointer to an array of strings
*/
char **strtow(char *str)
{
	int n;

	if (str == NULL || *str == '\0')
		return (NULL);

	n = wrdcnt(str);

	if (n == 0)
		return (NULL);

	return (allocate_words(str, n));
}
