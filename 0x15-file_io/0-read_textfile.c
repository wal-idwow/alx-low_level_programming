#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
	* read_textfile - reads text from a file and prints it
	* @filename: name of file to read
	* @letters: number of bytes to read/printed
	* Return: number of bytes read/printed
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	/* Open the file for reading */
	FILE *file = fopen(filename, "r");
	ssize_t bytes = 0;
	char buf[READ_BUF_SIZE];

	/* Check if the file is opened successfully and if letters is not zero */
	if (!file || letters == 0)
	{
		if (file)
		fclose(file);
		return (0);
	}

	/* Loop until the specified number of letters is reached or end of file */
	while (letters > 0)
	{
		/* Determine how many bytes to read in this iteration */
		size_t to_read = (letters < READ_BUF_SIZE) ? letters : READ_BUF_SIZE;

		/* Read from the file into the buffer*/
		size_t read_now = fread(buf, 1, to_read, file);

		/* Break the loop if nothing more to read */
		if (read_now == 0)
		break;

		/* Write the read data to standard output */
		fwrite(buf, 1, read_now, stdout);
		bytes += read_now;
		letters -= read_now;
	}
	fclose(file);

	/* Return the total number of bytes read/printed*/
	return (bytes);
}

