#include "shell.h"

/**
 * _getenv - To Get The Value Of Enviroment Variable By Name
 * @name: Environment variable name
 * Return: Environment variable value or NULL.
 */
char *_getenv(char *name)
{
	int i, t, p = 0;
	size_t name_len, item_len;
	char *item;

	name_len = _strlen(name);

	i = 0;
	while (environ[i])
	{


		if (_strncmp(name, environ[i], name_len) == 0)
		{
			item_len = _strlen(environ[i]) - name_len;
			item = malloc(sizeof(char) * item_len);

			for (t = name_len + 1; environ[i][t]; t++, p++)
			{
				item[p] = environ[i][t];
			}
			item[p] = '\0';

			return (item);
		}
		i++;
	}

	return (NULL);
}
