#ifndef _MONTY_H
#define _MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *get_func(char *func, stack_t **stack, unsigned int line_number);
void push_op(stack_t **stack, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void free_list(stack_t *head);
void nop_op(stack_t **stack, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void pchar_op(stack_t **stack, unsigned int line_number);
void pstr_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
void add_dnodeint_end(stack_t **stack, const int n);
void rotl_op(stack_t **stack, unsigned int line_number);
void rotr_op(stack_t **stack, unsigned int line_number);
void add_dnodeint(stack_t **stack, const int n);
extern int modusoperandi; /*Global variable to set stack or queue mode*/
#endif /*_MONTY_H_*/
