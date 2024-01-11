#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* generatePassword - Generates a password for the crackme5 executable.
* @input: The input string for password generation.
*
* Return: A dynamically allocated string containing the generated password.
*/
char *generatePassword(const char *input)
{
	const char *codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	int len = strlen(input), i, tmp;

	char *password = (char *)malloc(7 * sizeof(char));

	if (password == NULL) {
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	tmp = (len ^ 59) & 63;
	password[0] = codex[tmp];

	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += input[i];
	password[1] = codex[(tmp ^ 79) & 63];

	tmp = 1;
	for (i = 0; i < len; i++)
		tmp *= input[i];
	password[2] = codex[(tmp ^ 85) & 63];

	tmp = 0;
	for (i = 0; i < len; i++) {
		if (input[i] > tmp)
			tmp = input[i];
	}
	srand(tmp ^ 14);
	password[3] = codex[rand() & 63];

	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += (input[i] * input[i]);
	password[4] = codex[(tmp ^ 239) & 63];

	for (i = 0; i < input[0]; i++)
		tmp = rand();
	password[5] = codex[(tmp ^ 229) & 63];

	password[6] = '\0';
	return (password);
}

int main(int argc, char *argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <input>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	char *password = generatePassword(argv[1]);

	printf("%s\n", password);

	free(password);  // Don't forget to free the allocated memory
	return (EXIT_SUCCESS);
}
