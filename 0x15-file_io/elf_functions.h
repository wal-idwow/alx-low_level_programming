#ifndef ELF_FUNCTIONS_H
#define ELF_FUNCTIONS_H

/*
 * Desc: Header file containing prototypes for all functions
 *       written in the 100-elf_header.c file in 0x14-file_io directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>
#include <stdbool.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>

void it_is_elf(unsigned char *e_ident);
void magic_out(unsigned char *e_ident);
void class_out(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

#endif
