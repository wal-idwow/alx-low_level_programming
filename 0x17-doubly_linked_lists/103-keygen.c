#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <input>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char password[7], *code;
	int len = strlen(argv[1]), temp, i;

	code = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	temp = (len ^ 59) & 63;
	password[0] = code[temp];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += argv[1][i];
	password[1] = code[(temp ^ 79) & 63];

	temp = 1;
	for (i = 0; i < len; i++)
		temp *= argv[1][i];
	password[2] = code[(temp ^ 85) & 63];

	temp = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > temp)
			temp = argv[1][i];
	}
	srand(temp ^ 14);
	password[3] = code[rand() & 63];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += (argv[1][i] * argv[1][i]);
	password[4] = code[(temp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		temp = rand();
	password[5] = code[(temp ^ 229) & 63];

	password[6] = '\0';
	printf("%s\n", password);
	return EXIT_SUCCESS;
}
