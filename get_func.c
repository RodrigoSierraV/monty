#include "monty.h"

/**
 * get_func - selects function to execute.
 * @func: pointer to a char with an opcode.
 * @stack: pointer to the head of a doubly linked list
 * @line_number: line number from input file
 * Return: execution of a function pointer.
 */
stack_t *get_func(char *func, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t functions[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{NULL, NULL}
	};
	while (functions[i].opcode)
	{
		if (strcmp(func, functions[i].opcode) == 0)
		{
			functions[i].f(stack, line_number);
			return (*stack);
		}
		i++;
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
				line_number, func);
	exit(EXIT_FAILURE);
}
