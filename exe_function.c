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
	tmp_token = strtok(tmp, " \t\n");
	while (tmp_token != NULL)
	{
		size++;
		tmp_token = strtok(NULL, " \t\n");
	}
	free(tmp), size++;
	args = (char **)malloc(sizeof(char *) * size);
	if (args == NULL)
		return (NULL);
	for (i = 0; i < size - 1; i++)
	{
		token = strtok((i ? NULL : line), " \t\n");
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
		/*{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},*/
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(&state.stack, state.counter);
			test = 1;
		}
	}
	if (test == 0 && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", state.counter, opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * not_a_number - checks if a string is not a number
 * @s: string to check
 * Return: 0 if it is a number, 1 otherwise
 */
int not_a_number(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
		{
			if (i == 0 && s[0] == '-')
				continue;
			return (1);
		}
	return (0);
}
