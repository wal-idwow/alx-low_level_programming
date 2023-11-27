#include "main.h"

/**
	* create_file - creates a file and writes text content to it
	* @filename: name of the file to create
	* @text_content: content to write to the file
	* Return: 1 on success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written;

	if (!filename)
		return (-1);

	/* Open the file for writing, create it if it doesn't exist*/
	/* truncate it to 0 */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		/* Write text_content to the file */
		bytes_written = write(fd, text_content, strlen(text_content));
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);

	return (1);
}

