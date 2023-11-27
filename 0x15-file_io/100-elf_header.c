#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <elf.h>

void displayElfHeader(const char *filename) {
int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(98);
	}

	Elf64_Ehdr elfHeader;
ssize_t bytesRead = read(fd, &elfHeader, sizeof(Elf64_Ehdr));
	if (bytesRead != sizeof(Elf64_Ehdr) || elfHeader.e_ident[EI_MAG0] != ELFMAG0 ||
	elfHeader.e_ident[EI_MAG1] != ELFMAG1 || elfHeader.e_ident[EI_MAG2] != ELFMAG2 ||
	elfHeader.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		exit(98);
	}

	/* Seek to the beginning of the file */
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		perror("Error seeking to the beginning");
		exit(98);
	}

	/* Display ELF header information */
	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (int i = 0; i < EI_NIDENT; ++i)
	{
		printf("%02x ", elfHeader.e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             %s\n", elfHeader.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
								elfHeader.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "UNKNOWN");
	printf("  Data:                              %s\n", elfHeader.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", elfHeader.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n", elfHeader.e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", elfHeader.e_ident[EI_ABIVERSION]);

	printf("  Type:                              %s\n", elfHeader.e_type == ET_REL ? "REL (Relocatable file)" :
								elfHeader.e_type == ET_EXEC ? "EXEC (Executable file)" :
								elfHeader.e_type == ET_DYN ? "DYN (Shared object file)" :
								elfHeader.e_type == ET_CORE ? "CORE (Core file)" : "UNKNOWN");
	printf("  Entry point address:               0x%lx\n", elfHeader.e_entry);

	// Close the file
	close(fd);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
		exit(98);
	}

	const char *filename = argv[1];
	displayElfHeader(filename);

	return (0);
}
