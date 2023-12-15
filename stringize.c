#include "shell.h"

/**
 * stringize - to appends input after #
 * @buffer: input
 * Return:void
 */

void stringize(char *buffer)
{
	int p = 0;

	while (buffer[p] != '\0')
	{
		if (buffer[p] == '#')
		{

			buffer[p] = '\0';
			break;
		}
		p++;
	}
}
