#include <stdio.h>
#include "main.h"

/**
	* _atoi - converts a string to an integer
	* @s: string to be converted
	* Return: the int converted from the string
*/

int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;


		if (s[i] == '-')
		{
			sign = -1;
			i++;
		}

		while (s[i] != '0')
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
			}
			else
			{
				break;
			}
			i++;
		}
		return (num * sign);
}
/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

		if (argc != 3)
		{
			printf("Error\n");
			return (1);
		}

		num1 = _atoi(argv[1]);
		num2 = _atoi(argv[2]);

		if (num1 == 0 && *argv[1] != '0')
		{
			printf("Error\n");
			return (1);
		}
		if (num2 == 0 && *argv[2] != '0')
		{
			printf("Error\n");
			return (1);
		}

		result = num1 * num2;
		printf("%d\n", result);

	return (0);
}
