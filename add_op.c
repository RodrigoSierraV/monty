#include "monty.h"

/**
 * add_op - adds the top two elements of the stack.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 *
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	int add = 0;
	stack_t *new = NULL;

	(void)line_number;
	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}

	add = (*stack)->n + (*stack)->next->n;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = add;
	new->next = (*stack)->next;
	new->prev = *stack;
	(*stack)->next = (*stack)->next->prev = new;
	*stack = new;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
