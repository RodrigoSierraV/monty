#include "monty.h"

/**
 * push_op - pushes an element to stack.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 *
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	char *number = NULL;
	int integer;
	stack_t *new = NULL, *aux = *stack;

	number = strtok(NULL, " \n\t\r");
	if (number == NULL)
	{
		dprintf(STDERR_FILENO,
			 "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	integer = atoi(number);
	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = integer;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	*stack = new;
	new->next = aux;
	aux->prev = new;
}
