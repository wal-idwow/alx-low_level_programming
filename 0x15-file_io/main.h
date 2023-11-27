#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define READ_BUF_SIZE 1024

ssize_t read_textfile(const char *filename, size_t letters);
int _putchar(char c);




#endif

