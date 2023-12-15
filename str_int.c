#include "shell.h"

/**
 * _isalpha - to check whether a character is an alphabet
 * @c: character checked
 * Return: Success
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}

	else
	{
		return (0);
	}
}

/**
 * _atoi - to convert string to integer
 * @s: string
 * Return: integer
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + *s - '0';
		}

		else if (null_flag)
			break;
		s++;
	}


	if (sign < 0)
		total = (-total);


	return (total);
}
