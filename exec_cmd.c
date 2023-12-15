#include "shell.h"

/**
 * exec_cmd - A function to excute command
 * @cmdline: A Command to be tokenized
 * @line: line read from standard input
 * @av: the command-line arguments
 * Return: Success
 */
int exec_cmd(char **cmdline, char *line, char **av)
{
	int status;
	pid_t child_pid;

	if (*cmdline == NULL)
	{
		return (1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}


	if (child_pid == 0)
	{
		get_cmd(cmdline);

		if (execve(*cmdline, cmdline, environ) == -1)
		{
			perror(av[0]);
			free(line);
			free(cmdline);
			exit(1);
		}
		return (0);
	}
	wait(&status);
	return (0);
}
