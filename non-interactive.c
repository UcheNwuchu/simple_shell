#include "shell.h"

/**
 * read_file - To read Content of a file
 * @file_name: the name of the file
 * @av: the command-line arguments
 * Return: 0
 */
void read_file(char *file_name, char **av)
{
	FILE *fp;
	char *buffer = NULL;
	size_t lenght = 0;

	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		exit(1);
	}

	while ((getline(&buffer, &lenght, fp)) != -1)
	{

		exec_file(buffer, fp, av);

	}

	if (buffer)
	{
		free(buffer);
	}

	fclose(fp);
	exit(0);
}

/**
 * exec_file - To read from the file stream and execute commands
 * @buffer: command line
 * @fp: the file stream
 * @av: the command-line arguments
 * Return: void
 */

void exec_file(char *buffer, FILE *fp, char **av)
{
	char **command;

	command = tokenize_cmd(buffer);

	if (_strncmp(command[0], "exit", 4) == 0)
	{
		file_exit(command, buffer, fp);
	}

	exec_cmd(command, buffer, av);
	free(command);

}

/**
 * file_exit - To exit Shell non-interactive mode
 * @buffer: command line
 * @command: command that have been tokenized
 * @fp: the file stream
 * Return: void
 */

void file_exit(char **command, char *buffer, FILE *fp)
{
	int status;
	int t = 0;

	if (command[1] == NULL)
	{
		free(buffer);
		free(command);
		fclose(fp);
		exit(errno);
	}
	while (command[1][t])
	{
		if (_isalpha(command[1][t++]) < 0)
		{
			perror("Error");
		}
	}

	status = _atoi(command[1]);
	free(buffer);
	free(command);
	fclose(fp);
	exit(status);
}
