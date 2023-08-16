#include "function_pointers.h"

/**
	* print_name - prints a name
	* @name: person's name
	* @f: the printing function pointer
	* Return: void
*/

void print_name(char *name, void(*f)(char *))
{
	if (name && f)
		f(name);
}
