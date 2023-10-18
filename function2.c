#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
 */
void add(stack_t **stack, unsigned int line_counter)
{
	stack_t *tmp = *stack;
	int sum;
	(void)line_counter;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_counter);
		free_all(*stack, state.arg);
		exit(EXIT_FAILURE);
	}
	sum = tmp->n + (tmp->next)->n;
	pop(stack, line_counter);
	(*stack)->n = sum;
}
/**
 * nop - does nothing
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_counter)
{
	(void)stack;
	(void)line_counter;
}
/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_counter)
{
    stack_t *tmp = *stack;
    int sub;
    (void)line_counter;

    if (tmp == NULL || tmp->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_counter);
        free_all(*stack, state.arg);
        exit(EXIT_FAILURE);
    }
    sub = (tmp->next)->n - tmp->n;
    pop(stack, line_counter);
    (*stack)->n = sub;
}


