#include <monty.h>

/**
 * push - implements the push opcode
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
 */
void push(stack_t **stack, unsigned int line_counter)
{
	stack_t *new;

	if (stack == NULL)
		return;
	if (state.arg[1] == NULL || not_a_number(state.arg[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(state.arg[1]);
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
	if (new->next != NULL)
		(new->next)->prev = new;
}
/**
 * pall - implements the pall opcode
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_counter)
{
	stack_t *tmp = NULL;
	(void)line_counter;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - implements the pint opcode
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_counter)
{
	stack_t *tmp = NULL;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

