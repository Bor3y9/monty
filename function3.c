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
/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_counter: line number of the opcode
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_counter)
{
    stack_t *tmp = *stack;
    int mod;
    (void)line_counter;

    if (tmp == NULL || tmp->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_counter);
        free_all(*stack, state.arg);
        exit(EXIT_FAILURE);
    }
    if (tmp->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_counter);
        free_all(*stack, state.arg);
        exit(EXIT_FAILURE);
    }
    mod = (tmp->next)->n % tmp->n;
    pop(stack, line_counter);
    (*stack)->n = mod;
}