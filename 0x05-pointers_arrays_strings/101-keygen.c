#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
	* main - generate random password for 101-crackme
	* Return: zero
*/

int main(void)
{
	int sum;
	char b;

	srand(time(NULL));
	while (sum <= 2654)
	{
		b = rand() % 128;
		sum += b;
		putchar(b);
	}
	putchar(2772 - sum);
	return (0);
}
