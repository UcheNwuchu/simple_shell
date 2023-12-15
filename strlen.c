#include "shell.h"
#include <stdio.h>

/**
 * _strlen - function that returns the length of a string.
 * @s: pointer parameter passed to the function
 * Return: returns nothings
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;


	return (length);
}
