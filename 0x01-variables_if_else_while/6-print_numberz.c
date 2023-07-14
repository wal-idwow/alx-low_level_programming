#include <stdio.h>

/**
	*main - entry ponit
	*Description: task2
	*Return: Always 0 (Success)
*/

int main(void)
{
	int digit = 0;

	while (digit <= 9)
	{
		/*couvert digit to ASCII representetion*/
		putchar(digit + '0');
		digit++;
	}
	putchar('\n');

	return (0);
}
