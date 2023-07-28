#include "main.h"

/**
	* leet - encodes a string into 1337
	* @c: string
	* Return: string that is encoded
*/

char *leet(char *c)
{
	char *ab = c;
	char alpha[] = {'A', 'E', 'O', 'T', 'L'};
	int beta[] = {4, 3, 0, 7, 1};
	unsigned int d;

	while (*c)
	{
		for (d = 0; d < sizeof(alpha) / sizeof(char); d++)
		{
			/*32 is the difference between lowercase letters and apper ones*/

			if (*c == alpha[d] || *c == alpha[d] + 32)
			{
				*c = 48 + beta[d];
			}
		}
		c++;
	}
	return (ab);
}
