#include "monty.h"

/**
 * rotl_op - rotates the stack to the top.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 *
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	int top = 0;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	top = (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	add_dnodeint_end(stack, top);
}
