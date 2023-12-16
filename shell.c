#include "shell.h"

/**
 * main -the shell driver code
 * @ac: The number of command-line arguments
 * @av: The command-line arguments
 * Return: to indicate an error
 */
int main(__attribute__((unused)) int ac, char **av)
{
	char *message, **command;

	if (av[1])
	{
		read_file(av[1], av);

	}

	while (true)
	{
		if (isatty(STDIN_FILENO))
			printg("#cisfun$ ");
		message = _getline();
		if (message[0] == '\0')
			continue;
		command = tokenize_cmd(message);

		if (_strcmp(*command, "exit") == 0)
		{
			exit(0);
		}

		exec_cmd(command, message, av);
		free(command);
		free(message);
	}
	return (1);
}
