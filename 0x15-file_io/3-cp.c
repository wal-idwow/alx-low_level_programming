#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/*Globale variables*/
char *buffer_creator(char *file);

void close_file(int fd);

/**
* buffer_creator - Allocates 1024 bytes for a buffer.
* @file: The name of the file buffer is storing chars for.
* Return: A pointer to the newly-allocated buffer.
*/

char *buffer_creator(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
* close_file - Closes file descriptors.
* @fd: The file descriptor to be closed.
*/
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
* main - Copies the contents of a file to another file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: If the argument count is incorrect - exit code 97.
*              If file_from does not exist or cannot be read - exit code 98.
*              If file_to cannot be created or written to - exit code 99.
*              If file_to or file_from cannot be closed - exit code 100.
*/
int main(int argc, char *argv[])
{
	int file_from, file_to, rd, wr;

	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = buffer_creator(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	rd = read(file_from, buf, 1024);
	umask(0);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	do {
		if (file_from == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		wr = write(file_to, buf, rd);
		if (file_to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		rd = read(file_from, buf, 1024);
		file_from = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(buf);
	close_file(file_from);
	close_file(file_to);

	return (0);
}
