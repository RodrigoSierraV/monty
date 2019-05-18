#include "monty.h"

/**
 * rotr_op - rotates the stack to the bottom.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 *
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
	int bottom = 0;
	stack_t *aux = *stack, *new = NULL;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	while (aux->next)
		aux = aux->next;
	bottom = aux->n;
	aux->prev->next = NULL;
	free(aux);
	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = bottom;
	new->next = *stack;
	new->prev = NULL;
	(*stack)->prev = new;
	*stack = new;
}
