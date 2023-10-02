#include "main.h"

#define PERMISSIONS (S_IROTH | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP)
#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOCLOSE "Error: Can't close fl %d\n"
#define USAGE "Usage: cp file_from file_to\n"

/**
	* main - programme
	* @arc: argument count
	* @arv: argument vector
	* Return: 1 on success 0 on failure
*/

int main(int arc, char **arv)
{
	int from_fl = 0, to_fl = 0;
	ssize_t a;
	char buf[READ_BUF_SIZE];

	if (arc != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	from_fl = open(arv[1], O_RDONLY);
	if (from_fl == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, arv[1]), exit(98);
	to_fl = open(arv[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (to_fl == -1)
		dprintf(STDERR_FILENO, ERR_NOWRITE, arv[2]), exit(99);

	while ((a = read(from_fl, buf, READ_BUF_SIZE)) > 0)
		if (write(to_fl, buf, a) != a)
			dprintf(STDERR_FILENO, ERR_NOWRITE, arv[2]), exit(99);
	if (a == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, arv[1]), exit(98);

	from_fl = close(from_fl);
	to_fl = close(to_fl);
	if (from_fl)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, from_fl), exit(100);
	if (to_fl)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, to_fl), exit(100);

	return (EXIT_SUCCESS);
}
