#include "monty.h"

/**
 * get_func - selects function to execute.
 * @func: pointer to a char with an opcode.
 *
 * Return: execution of a function pointer or NULL.
 */
void (*get_func(char *func))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t functions[] = {
		{"push", push_op},
		{"pall", pall_op},
		{NULL, NULL}
	};
	while (functions[i].opcode)
	{
		if (strcmp(func, functions[i].opcode) == 0)
			return (functions[i].f);
		i++;
	}
	return (NULL);
}
