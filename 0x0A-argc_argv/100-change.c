#include <stdio.h>
#include <stdlib.h>

/**
	* main - the minimum number of coins
	* to make change for an amount of money.
	* @argc: number of command line arguments
	* @argv: pointer to an array of command line argumrent
	* Return: 0 success - non-zero-fail
*/

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
	int i, lscents = 0, money = atoi(argv[1]);
	int cents[] = {25, 10, 5, 2, 1};

	for (i = 0; i < 5; i++)
	{
		if (money >= cents[i])
		{
			lscents += money / cents[i];
			money = money % cents[i];
			if (money % cents[i] == 0)
			{
				break;
			}
		}
	}
	printf("%d\n", lscents);
	}
	else
	{
		printf("Error\n");
		return (0);
	}
	return (0);
}
