#include "monty.h"

/**
 * _getargs - splits a line into arguments
 * @line: line to split
 * Return: array of arguments
 */
char **_getargs(char *line)
{
	char **args = NULL, *token, *tmp, *tmp_token;
	int size = 0, i;

	tmp = _strdup(line);
	if (tmp == NULL)
		return (NULL);
	tmp_token = custom_strtok(tmp, " \t\n");
	while (tmp_token != NULL)
	{
		size++;
		tmp_token = custom_strtok(NULL, " \t\n");
	}
	free(tmp), size++;
	args = (char **)malloc(sizeof(char *) * size);
	if (args == NULL)
		return (NULL);
	for (i = 0; i < size - 1; i++)
	{
		token = custom_strtok((i ? NULL : line), " \t\n");
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(args[i]);
			free(args);
			return (NULL);
		}
	}
	args[size - 1] = NULL;
	return (args);
}
/**
 * select_function - selects the correct function to perform the operation
 * @opcode: operation code
 * Return: pointer to the correct function
 */

void select_function(char *opcode)
{
    int i, test = 0;

    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {"sub", sub},
        {"div", div},
        {"mul", mul},
        {"mod", mod},
        {"pchar", pchar},
        {"pstr", pstr},
        {"rotl", rotl},
        {"rotr", rotr},
        {NULL, NULL}
    };

    for (i = 0; opcodes[i].opcode != NULL; i++)
    {
        if (_strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(&state.stack, state.counter);
            test = 1;
            break;
        }
    }
    if (test == 0)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", state.counter, opcode);
        exit(EXIT_FAILURE);
    }
}