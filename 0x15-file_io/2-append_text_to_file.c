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
	* append_text_to_file -  appends text to a file.
	* @filename: name of file to create
	* @text_content: text to write
	* Return: 1 on success 0 on failure
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int fr;
	ssize_t byt = 0, ln = _strlen(text_content);

	if (!filename)
		return (-1);
	fr = open(filename, O_WRONLY | O_APPEND);
	if (fr == -1)
		return (-1);
	if (ln)
		byt = write(fr, text_content, ln);
	close(fr);
	return (byt == ln ? 1 : -1);
}
