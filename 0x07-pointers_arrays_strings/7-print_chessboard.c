#include "main.h"

/**
	* print_chessboard - prints chessboard
	* @a: rows
	* Return: nothing
*/

void print_chessboard(char (*a)[8])
{
	int ar, br;

	for (ar = 0; ar < 8; ar++)
	{
		for (br = 0; br < 8; br++)
		{
			_putchar(a[ar][br]);
		}
		_putchar('\n');
	}
}
