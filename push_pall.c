#include <monty.h>
/**
 * push - ...
 * @stack: ...
 * @line_number: ...
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new;
    if (stack==NULL)
            return;
    if(state.arg[1] == NULL || not_a_number(state.arg[1]))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    new = malloc(sizeof(stack_t));
    if (new == NULL)
        fprintf(stderr, "Error: malloc failed\n"),exit(EXIT_FAILURE);
    
    new->n = atoi(state.arg[1]);
    new->prev = NULL;
    new->next = *stack;
    *stack = new;
    if(new->next != NULL)
        (new->next)->prev = new;
}
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = NULL;
    (void)line_number;

    tmp = *stack;
    while(tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
void top(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = NULL;
    (void)line_number;

    if(tmp == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", tmp->n);
    

}

/**
 * not_a_number - ...
 * @s: ...
 * Return: 1 or 0
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