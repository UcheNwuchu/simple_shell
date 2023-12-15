#include "shell.h"

/**
 * _strtok - to tokinizes a string
 * @str: string to tokinized
 * @delim: delimeter
 * Return: pointer
 */

char *_strtok(char *str, char *delim)
{
	static char *token, *beginning;
	int t;

	if (str)
	{
		token = str;
	}
	if (token == NULL)
	{
		return (NULL);
	}

	beginning = token;

	t = 0;
	while (token[t] && _strchr(delim, token[t]) != NULL)
	{
		token++;
	}

	if (token[t] == '\0')
	{
		token = NULL;
		return (NULL);
	}


	while (token[t] && _strchr(delim, token[t]) == NULL)
	{
		token++;
	}

	if (token[t] != '\0')
	{
		token[t] = '\0';
		token++;
	}

	return (beginning);
}
