#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - Generates and prints psswrds for the crackme5 executable
 * @argc: arguments number of supplied to the program
 * @argv: array of pointers to the arguments
 * Return: (0) Always
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char psswrd[7], *code;
	int len = strlen(argv[1]), temp, i;

	code = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	temp = (len ^ 59) & 63;
	psswrd[0] = code[temp];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += argv[1][i];
	psswrd[1] = code[(temp ^ 79) & 63];

	temp = 1;
	for (i = 0; i < len; i++)
		temp *= argv[1][i];
	psswrd[2] = code[(temp ^ 85) & 63];

	temp = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > temp)
			temp = argv[1][i];
	}
	srand(temp ^ 14);
	psswrd[3] = code[rand() & 63];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += (argv[1][i] * argv[1][i]);
	psswrd[4] = code[(temp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		temp = rand();
	psswrd[5] = code[(temp ^ 229) & 63];

	psswrd[6] = '\0';
	printf("%s", psswrd);
	return (0);
}
