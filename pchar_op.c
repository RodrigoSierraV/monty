#include "monty.h"

/**
 * pchar_op - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 * Return: Nothing
 */

void pchar_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
