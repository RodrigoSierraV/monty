#include "monty.h"

/**
 * pop_op - removes the top element of the stack.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 * Return: Nothing
 */

void pop_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
