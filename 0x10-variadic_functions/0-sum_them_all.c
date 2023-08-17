#include "variadic_functions.h"

/**
	* sum_them_all - sum variables arguments
	* @n: argument's number
	* @...: integers to sum
	* Return: integer's sum
*/

int sum_them_all(const unsigned int n, ...)
{
	int a = 0, b = n;
	va_list ap;

	if (!n)
		return (0);
	va_start(ap, n);
	while (b--)
		a += va_arg(ap, int);
	va_end(ap);
	return (a);
}
