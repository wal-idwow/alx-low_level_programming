#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
	* check_num - Checks if a string contains only digits.
	* @str: The input string to check
	*
	* Retrun: (1) if the string contains only digits, (0) otherwise
*/

int check_num(char *str)
{
	/* Declaring variables */
	unsigned int count;

	count = 0;
	while (count < strlen(str)) /*count string*/
	{
		if (!isdigit(str[count])) /*check str = digit*/
		{
			return (0);
		}
		count++;
	}
	return (1);
}

/**
	* main - Entry point
	* @argc: the argument count
	* @argv: the argument array
	*
	* Return: (0) on success, (1) on error
*/

int main(int argc, char *argv[])
{
	int sum = 0;
	int i;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		int j = 0;

		while (argv[i][j])
		{
			if (!check_num(argv[i]))
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}

		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
