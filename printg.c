#include "shell.h"

/**
 * printg - to prints lines of strings
 * @c: string to be printed
 */

void printg(char *c)
{
	write(1, c, _strlen(c));
}
