#include "main.h"
#include <stdio.h>

/**
	* is_prime_number - chec if n is a prime number
	* @notn: int
	* @n: int
	* Return: 0 or 1
*/

int check_prime(int n, int notn);
int is_prime_number(int n)
{
	return (check_prime(n, 2));
}

/**
	* check_prime - check all number < n if they can divide it
	* @n: int
	* @notn: int
	* Return: int
*/

int check_prime(int n, int notn)
{
	if (notn >= n && n > 1)
		return (1);
	else if (n % notn == 0 || n <= 1)
		return (0);
	else
		return (check_prime(n, notn + 1));
}
