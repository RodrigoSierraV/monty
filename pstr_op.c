#include "monty.h"

/**
 * pstr_op - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 * Return: Nothing
 */

void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;
	while (aux->next && aux->n != 0 && aux->n >= 0 && aux->n <= 127)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}
