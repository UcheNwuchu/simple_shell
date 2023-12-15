#include "shell.h"

/**
 * _getline - to read input from standard input
 * Return: returns the input
 */
char *_getline(void)
{
	size_t buffer_size = BUFSIZE, new_buffer_size, r;
	int cmd = 0;
	char *buffer = malloc(buffer_size);

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	r = 0;
	while (cmd != EOF && cmd != '\n')
	{
		fflush(stdin);
		if (read(STDIN_FILENO, &cmd, 1) == 0)
		{
			free(buffer);
			exit(0);
		}

		buffer[r] = cmd;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		new_buffer_size = buffer_size + 1;

		if (r >= buffer_size)
		{
		buffer = _realloc(buffer, buffer_size, new_buffer_size);
			if (buffer == NULL)
			return (NULL);
		}
		r++;
	}
	buffer[r] = '\0';
	stringize(buffer);
	return (buffer);
}
