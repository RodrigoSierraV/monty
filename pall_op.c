#include "monty.h"

/**
 * pall_op - prints elements of stack.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 * Return: Nothing
 */

void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;

	while (aux->next)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
