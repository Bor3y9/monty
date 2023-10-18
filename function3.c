#include "monty.h"
/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_counter)
{
    stack_t *tmp = *stack;
    int mul;
    (void)line_counter;

    if (tmp == NULL || tmp->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_counter);
        free_all(*stack, state.arg);
        exit(EXIT_FAILURE);
    }
    mul = (tmp->next)->n * tmp->n;
    pop(stack, line_counter);
    (*stack)->n = mul;
}