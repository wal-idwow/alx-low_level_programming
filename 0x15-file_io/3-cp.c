#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point
 * @argc: arguments number
 * @argv: arguments strings's array
 * return: 0 on success, # values on failure
*/
int main(int argc, char *argv[])
{
    int file_from;
    int file_to;
    int read_bytes;
    int write_bytes;
    char buf[BUFFER_SIZE];


    /*checking number of arguments*/
    if (argc != 3)
    {
        dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    /* opening the source file for reading on failur exit 98*/
    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1)
    {
        dprintf(2, "Error: can't read from file %s\n", argv[1]);
        exit(98);
    }

    /*opening file to for writing on failur exit 99 */
    umask(0);
    file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (file_to == -1)
    {
        dprintf(2, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }

    /*cp content from file_from to file_to on fail exit 99*/
    while ((read_bytes = read(file_from, buf, BUFFER_SIZE)) > 0)
    {
        write_bytes = write(file_to, buf, read_bytes);
        if (write_bytes != read_bytes)
        {
            dprintf(2, "Error: cant write to %s\n", argv[2]);
            close(file_from);
            close(file_to);
            exit(99);
        }        
    }
    
    /*checking errors in reading if existe exit 98*/
    if (read_bytes == -1)
    {
        dprintf(2, "Error: can't read from file %s\n", argv[1]);
        close(file_from);
        close(file_to);
        exit(98);
    }

    /*closing the file descriptor on failur exit 100*/
    if (close(file_from) == -1 || close(file_to) == -1)
    {
        dprintf(2, "Error: Can't close fd %d\n", (close(file_from) == -1) ? file_from : file_to);
        exit(100);
    }

    return (0);
    
}