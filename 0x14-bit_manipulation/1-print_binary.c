#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: the number to print
 * Return: void
 */
void print_binary(unsigned long int n)
{
    if (n > 1)
        print_binary(n >> 1); /* Recursively call with the rightmost bits*/

    _putchar((n & 1) + '0'); /* Print the current bit (0 or 1)*/
}