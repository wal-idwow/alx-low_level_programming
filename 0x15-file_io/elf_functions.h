#ifndef ELF_FUNCTIONS_H
#define ELF_FUNCTIONS_H

/**
 * header file containing prototypes of functions
 *          in 100-elf_header.c file
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
void data_out(unsigned char *e_ident);
void version_out(unsigned char *e_ident);
void abi_out(unsigned char *e_ident);
void osabi_out(unsigned char *e_ident);
void type_out(unsigned int e_type, unsigned char *e_ident);
void entry_out(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

#endif
