#include "main.h"

/**
	* print_binary -  prints the binary representation of a number.
	* @n: the number to print
	* Return: void
*/

void print_binary(unsigned long int n)
{
	int bt = sizeof(n) * 8, print = 0;

	while (bt)
	{
		if (n & 1L << --bt)
		{
			_putchar('1');
			print++;
		}
		else if (print)
			_putchar('0');
	}
	if (!print)
		_putchar('0');
}
