#include "monty.h"

/**
 * div_op - subs the top two elements of the stack.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 *
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = div;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
