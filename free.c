#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: pointer to the head of the stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * free_buffer - frees the buffer
 * @buffer: buffer to free
 * Return: void
 */
void free_buffer(char **buffer)
{
	int i;

	for (i = 0; buffer[i]; i++)
		free(buffer[i]);
	free(buffer);
}
