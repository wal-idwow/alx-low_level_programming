#include "main.h"

/**
	* _strlen - returns the length of a string
	* @s: the string whose length to check
	* Return: integer length of strin
*/

int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}

/**
	* create_file -  creates a file.
	* @filename: name of file to create
	* @text_content: text to write
	* Return: 1 on success 0 on failure
*/

int create_file(const char *filename, char *text_content)
{
	int f;
	ssize_t byt = 0, ln = _strlen(text_content);

	if (!filename)
		return (0);
	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (f == -1)
		return (-1);
	if (ln)
		byt = write(f, text_content, ln);
	close(f);
	return (byt == ln ? 1 : -1);
}
