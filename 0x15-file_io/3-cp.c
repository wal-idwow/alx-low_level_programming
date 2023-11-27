#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
	* main - Programme
	* @argc: argument account
	* @argv: argument vector
	* Return: 0 success
*/

int main(int argc, char *argv[])
{
	/* Check if the correct number of arguments is provided*/
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
		return (1);  /* Exit code 1 indicates incorrect usage*/
	}

	int source_fd, dest_fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	/* Open the source file in read-only mode */
	source_fd = open(argv[1], O_RDONLY);

	/* Open the destination file in write-only mode */
	/*  create if not exist, truncate to zero */
	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	/* Check if file opening is successful */
	if (source_fd == -1 || dest_fd == -1)
	{
		perror("Error");
		/* Exit code 2 or 3 for file opening failure*/
		return (source_fd == -1 ? 2 : 3);
	}
	/* Loop to read and write in chunks*/
	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		ssize_t bytes_written = write(dest_fd, buffer, bytes_read);

		if (bytes_written != bytes_read)
		{
			perror("Error");
			return (4);  /* Exit code 4 for writing error */
		}
	}
	if (bytes_read == -1)
	{
		perror("Error");
		return (5);  /* Exit code 5 for reading error */
	}
	close(source_fd), close(dest_fd);
	return (0);  /* Exit code 0 indicates successful execution */
}

