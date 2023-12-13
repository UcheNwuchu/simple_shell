#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - To checks if character is a delimeter
 * @d: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char d, char *delim)
{
	while (*delim)
		if (*delim++ == d)
			return (1);
	return (0);
}

/**
 *_isalpha - To check for alphabetic character
 *@d: The character to input
 *Return: 1 if d is alphabetic, 0 otherwise
 */

int _isalpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - To convert a string to an integer
 *@t: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *t)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0;  t[j] != '\0' && flag != 2; j++)
	{
		if (t[j] == '-')
			sign *= -1;

		if (t[j] >= '0' && t[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (t[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
