#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_counter)
{
    stack_t *tmp = *stack;
    (void)line_counter;

    if (tmp == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_counter);
        free_all(*stack, state.arg);
        exit(EXIT_FAILURE);
    }
    if (tmp->n < 0 || tmp->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_counter);
        free_all(*stack, state.arg);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", tmp->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_counter)
{
    stack_t *tmp = *stack;
    (void)line_counter;

    while (tmp != NULL && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
    {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }
    printf("\n");
}
