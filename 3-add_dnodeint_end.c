#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: pointer to the head of the list
 * @n: number to insret in the list.
 * Return: pointer to the new node.
 */
void add_dnodeint_end(stack_t **stack, const int n)
{
	stack_t *aux = *stack, *new = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	while (aux->next)
		aux = aux->next;
	aux->next = new;
	new->prev = aux;
}
