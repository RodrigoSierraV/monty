#include "monty.h"

/**
 * swap_op - swaps the top two elements of the stack..
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 *
 */

void swap_op(stack_t **stack, unsigned int line_number)
{

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next->next)
	{
		*stack = (*stack)->next;
		(*stack)->next = (*stack)->prev;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next->next = NULL;
		return;
	}
	*stack = (*stack)->next;
	(*stack)->prev->next = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}
