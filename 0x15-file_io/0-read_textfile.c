#include "main.h"

/**
* read_textfile - reads text from a file and prints it
* @filename: name of file to read
* @letters: number of bytes to read/printed
* Return: number of bytes read/printed
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf; /*Buffer to store read content*/

	ssize_t file; /*File descriptor*/
	ssize_t rd; /*bytes read*/
	ssize_t wr; /*bytes written*/

	/*Open the file in read-only mode*/
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	/*Allocate memory for the buffer*/
	buf = malloc(sizeof(char) * letters);
	/*Read from the file into the buffer*/
	rd = read(file, buf, letters);
	/*Write the content of the buffer to STDOUT*/
	wr = write(STDOUT_FILENO, buf, rd);

	free(buf);
	close(file);
	return (wr);
}
