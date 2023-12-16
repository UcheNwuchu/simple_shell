#include "shell.h"

/**
 * _strdup - to duplicate a string
 * @str: string to be debugged
 */

char *_strdup(char *str)
{
	size_t len;
	char *duplicate;

	len = _strlen(str) + 1;
	duplicate = malloc(sizeof(char) * len);

	if (duplicate != NULL)
	{
		_strcpy(duplicate, str);
	}

	return (duplicate);
}
