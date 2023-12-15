#include "shell.h"

/**
 * get_cmd - to search for a command specified by the PATH
 * @command: input command
 * Return: Failure.
 */

int get_cmd(char **command)
{
	char *path;
	char *dir;
	char *cmd_path;
	struct stat st;

	path = _getenv("PATH");
	dir = strtok(path, ":");

	while (dir)
	{
		cmd_path = path_to_cmd(*command, dir);
		if (stat(cmd_path, &st) == 0)
		{
			*command = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}

		free(cmd_path);
		dir = strtok(NULL, ":");
	}
	free(path);

	return (1);
}
/**
 * path_to_cmd - to create path to a command
 * @str1: executable command
 * @str2: directory  containing command
 * Return: the path
 */

char *path_to_cmd(char *str1, char *str2)
{
	char *command;
	size_t lenght;
	int len1;
	int len2;

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	lenght = len1 + len2 + 1;
	command = malloc(sizeof(char) * lenght + 1);

	_memset(command, 0, (lenght + 1));

	command = _strcat(command, str2);
	command = _strcat(command, "/");
	command = _strcat(command, str1);

	return (command);
}
