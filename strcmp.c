#include "shell.h"

/**
 * _strcmp - function that compares two strings.
 * @s1: parameter one
 * @s2: parameter two
 * Return: returns an integer value
 */

int _strcmp(char *s1, char *s2)
{
	int i;
	int r;

	i = 0;
	while (s1[i] && s2[i])
	{

		if (s1[i] != s2[i])
		{
			r = s1[i] - s2[i];

			return (r);
		}
		i++;
	}

	return (0);
}
