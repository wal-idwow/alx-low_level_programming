#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
	* main - Programme
	* @argc: argument account
	* @argv: argument vector
	* Return: 0 success
*/

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t n;

	fd_from = open(argv[1], O_RDONLY);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd_from == -1 || fd_to == -1)
	{
		perror("Error");
		return (fd_from == -1 ? 98 : 99);
	}

	while ((n = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(fd_to, buffer, n) != n)
		{
			perror("Error");
			return (99);
		}
	}

	if (n == -1)
	{
		perror("Error");
		return (98);
	}

	close(fd_from);
	close(fd_to);

	return (0);
}

