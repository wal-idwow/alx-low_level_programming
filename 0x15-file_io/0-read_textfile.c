#include "main.h"

/**
	* read_textfile - reads tex from a file and prints it
	* @filename: name of file to read
	* @letters : number of bytes to read/printed
	* Return: number bytes read/printed
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int f;
	ssize_t byt;
	char buf[READ_BUF_SIZE * 8];

	if (!filename || !letters)
		return (0);
	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	byt = read(f, &buf[0], letters);
	byt = write(STDOUT_FILENO, &buf[0], byt);
	close(f);
	return (byt);
}
