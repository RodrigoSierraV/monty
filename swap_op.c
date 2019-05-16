#include "monty.h"

/**
 * swap_op - swaps the top two elements of the stack..
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 *
 */

void swap_op(stack_t **stack, unsigned int line_number)
{

	if (!*stack || !(*stack)->next:)
        {
                dprintf(STDERR_FILENO, "can't swap, stack too short\n");
                exit(EXIT_FAILURE);
        }
	(void)*stack;
	(void)line_number;
}
