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
	int integer, is, i = 0;

	number = strtok(NULL, " \n\t\r");
	if (number == NULL)
	{
		dprintf(STDERR_FILENO,
			 "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (number[i])
	{
		is =  isdigit(number[i]);
		if ((is == 0 && number[i] != '-') || isdigit(number[i + 1] == 0))
		{
			dprintf(STDERR_FILENO,
			"L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	integer = atoi(number);
	if (modusoperandi == 1)
	{
		add_dnodeint_end(stack, integer);
		return;
	}
	add_dnodeint(stack, integer);
}
