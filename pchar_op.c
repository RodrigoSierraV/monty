#include "monty.h"

/**
 * pchar_op - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 * Return: Nothing
 */

void pchar_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	printf("%c\n", (*stack)->n);
}
