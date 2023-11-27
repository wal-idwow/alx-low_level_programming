#include "main.h"

/**
	* append_text_to_file - appends text to a file
	* @filename: name of the file
	* @text_content: text to append to the file
	* Return: 1 on success, -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written;
	size_t len;

	/* Check if the filename or text_content is NULL */
	if (!filename || !text_content)
		return (-1);

	/* Open the file for writing and appending */
	fd = open(filename, O_WRONLY | O_APPEND);

	/* Check if opening the file failed */
	if (fd == -1)
		return (-1);

	/*get the length of the text_content*/
	len = strlen(text_content);

	/* Write text_content to the file */
	bytes_written = write(fd, text_content, len);

	/* Check if writing to the file failed */
	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);

	/* Return 1 to indicate success */
	return (1);
}
