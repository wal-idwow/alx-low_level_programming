#include <stdio.h>
/**
 * main - Entry point
 * Description: print the size of various type with sizeof
 * Return: always 0 (Success)
*/
int main(void)
{
	int a = sizeof(long long int);

	printf("size of a char: %zu byte(s)\n", (unsigned int)sizeof(char));
	printf("size of an int: %zu byte(s)\n", (unsigned int)sizeof(int));
	printf("size of a long int: %zu byte(s)\n", (unsigned int)sizeof(long int));
	printf("size of a long long int: %d byte(s)\n", a);
	printf("size of a float: %zu byte(s)\n", (unsigned int)sizeof(float));
	return (0);
}
