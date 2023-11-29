#include "main.h"

/**
 * main -  program that copies the content of a file to another file.
 * @ac: argument count
 * @av: argument vector
 * Return: 1 on success 0 on failure
*/
int main(int ac, char **av)
{
	int file_from = 0, file_to = 0;
	ssize_t i;
	char buf[READ_BUF_SIZE];

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);

	file_from = open(av[1], O_RDONLY);
	if (file_from == -1)
		dprintf(STDERR_FILENO, ERR_READ, av[1]), exit(98);

	file_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (file_to == -1)
		dprintf(STDERR_FILENO, ERR_WRITE, av[2]), exit(99);

	while ((i = read(file_from, buf, READ_BUF_SIZE)) > 0)
		if (write(file_to, buf, i) != i)
			dprintf(STDERR_FILENO, ERR_WRITE, av[2]), exit(99);

	if (i == -1)
		dprintf(STDERR_FILENO, ERR_READ, av[1]), exit(98);

	file_from = close(file_from);
	file_to = close(file_to);
	if (file_from)
		dprintf(STDERR_FILENO, ERR_CLOSE, file_from), exit(100);
	if (file_to)
		dprintf(STDERR_FILENO, ERR_CLOSE, file_from), exit(100);

	return (EXIT_SUCCESS);
}
