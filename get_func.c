#include "monty.h"
int modusoperandi = 0;
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
		{"push", push_op}, {"pall", pall_op},
		{"pint", pint_op}, {"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"mod", mod_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{NULL, NULL}
	};
	while (functions[i].opcode)
	{
		if (strcmp(func, "stack") == 0)
		{
			modusoperandi = 0;
			return (*stack);
		}
		if (strcmp(func, "queue") == 0)
		{
			modusoperandi = 1;
			return (*stack);
		}
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
