#include "shell.h"

/**
 * _memset - A function that fills memory with a constant byte.
 * @s: First parameter of the function
 * @b: Second parameter of the function
 * @n: Third parameter of the function
 * Return: returns string of characters
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
