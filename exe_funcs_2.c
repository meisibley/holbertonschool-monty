#include "monty.h"

/**
 * func_add - adds the top two elements of the stack
 * @stack: adds the top node's value to next, and pop the first one
 * @count: the monty file's line number
 *
 * Return: nothing
 */
void func_add(stack_t **stack, unsigned int count)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}

/**
 * func_nop - doesn't do anything
 * @stack: doubly linked list
 * @count: line number
 *
 * Return: nothing
 */
void func_nop(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;
}
