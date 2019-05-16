#include "monty.h"

/**
 * main - interpreter for Monty ByteCodes files.
 * @argc: number of arguments from command line.
 * @argv: pointer to an array with arguments from command line.
 * Return: always 0.
*/
int main(int argc, char *argv[])
{
	size_t bufsize = 0;
	char *buffer = NULL, delim[] = " \t\r\n", *func = NULL;
	FILE *stream = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		dprintf(STDERR_FILENO, "Error: can´t open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*Read lines from source file*/
	while (getline(&buffer, &bufsize, stream) != -1)
	{
		line_number++;
		func = strtok(buffer, delim);
		if (func != NULL)
		{
			get_func(func, &stack, line_number);
		}
	}
	return (0);
}
