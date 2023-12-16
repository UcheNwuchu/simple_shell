#include "shell.h"

/**
 * tokenize_cmd - to tokenize line Of Input
 * @message: input
 * Return: list of tokenized input
 */

char **tokenize_cmd(char *message)
{
	char **array, *token;
	int i;
	char delim[] = {"\n "};

	if (message == NULL)
	{
		return (NULL);
	}

	array = malloc(sizeof(char *) * BUFSIZE);
	if (array == NULL)
	{
		perror("parse failed!");
		return (NULL);
	}

	token = strtok(message, delim);

	i = 0;
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;

	return (array);

}
