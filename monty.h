#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int intvalue;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struck instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_count);
} instruction_t;

void tokenize(char *line_buf, unsigned int line_count, stack_t **stack);
void exe_opcode(char *op, char *value, unsigned int count, stack_t **stack);
int handle_value(char *value, unsigned int count);
void func_push(stack_t **stack, unsigned int line_count);
void func_pall(stack_t **stack, unsigned int line_count);
void func_pint(stack_t **stack, unsigned int line_count);
void func_pop(stack_t **stack, unsigned int line_count);
void func_swap(stack_t **stack, unsigned int line_count);
void func_add(stack_t **stack, unsigned int line_count);
void func_nop(stack_t **stack, unsigned int line_count);
void free_stack(stack_t *stack);

#endif
