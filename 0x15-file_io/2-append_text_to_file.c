#include "main.h"

/**
	* append_text_to_file - appends text to a file
	* @filename: name of the file
	* @text_content: text to append to the file
	* Return: 1 on success, -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int wrr; /*result of the write operation*/
	int file; /*file descriptor for the file*/
	int num_lett; /*number of letters in the text_content*/

	if (!filename)
		return (-1);

	/*open the file for writing and appending*/
	file = open(filename, O_WRONLY | O_APPEND);

	/*check if opening the file failed*/
	if (file == -1)
		return (-1);

	/*check if text_content is not NULL*/
	if (text_content)
	{
		/*calculate the number of letters in text_content*/
		for (num_lett = 0; text_content[num_lett]; num_lett++)
			;
		/*write text_content to the file*/
		wrr = write(file, text_content, num_lett);

		/*check if writing to the file failed*/
		if (wrr == -1)
			return (-1);
	}

	close(file);
	return (1);
}
