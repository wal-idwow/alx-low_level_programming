#include <stdio.h>
/**
 * main - Entry point
 * Description: print the size of various type with sizeof
 * Return: always 0 (Success)
*/
int main(void)
{
	int a = sizeof(long long int);
	int b = sizeof(long int);
	int c =	sizeof(int);
	int d = sizeof(float);
	int f =	sizeof(char);

	printf("size of a char: %d byte(s)\n", f);
	printf("size of an int: %d byte(s)\n", c);
	printf("size of a long int: %d byte(s)\n", b);
	printf("size of a long long int: %d byte(s)\n", a);
	printf("size of a float: %d byte(s)\n", d);
	return (0);
}
