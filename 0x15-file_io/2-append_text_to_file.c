#include "main.h"

/**
	* append_text_to_file - appends text to a file
	* @filename: name of the file
	* @text_content: text to append to the file
	* Return: 1 on success, -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int op;
	int wr;
	int len = 0;

	if (filename == NULL)
	{
		for (len = 0; text_content[len]; len++)
			;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	wr = write(op, text_content, len);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);
	return (1);
}
