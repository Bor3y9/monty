#include "monty.h"


/**
 * readline - reads lines from a file
 *
 * Return: a pointer to a line or NULL
 */
char *readline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * if_empty - checks if a string is empty
 * @line: string to check
 * Return: 1 if empty, 0 if not
 */
int if_empty(char *line)
{
	int i;

	if (line[0] == '\0' || _strcmp(line, "\n") == 0)
		return (1);

	for (i = 0; line[i]; i++)
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (0);
	}
	return (1);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	state_info state = init_state_info;

	state.stack = NULL;
	state.counter = 0;
	state.buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	state.file = fopen(argv[1], "r");
	if (state.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		state.buffer = readline();
		state.counter++;
		if (state.buffer == NULL)
		{
			free(state.buffer);
			break;
		}
		if (if_empty(state.buffer))
		{
			free(state.buffer);
			continue;
		}

		state.arg = _getargs(state.buffer);
		free(state.buffer);
		select_function(state.arg[0]);
		free(state.arg);
	}
	fclose(state.file);
	free_stack(state.stack);
	return (0);
}
