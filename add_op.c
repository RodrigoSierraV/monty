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

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	add = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = add;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
