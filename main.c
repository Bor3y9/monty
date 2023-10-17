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
    state.stack = NULL;
    state.counter = 0;
    state.buffer = NULL;
    
}