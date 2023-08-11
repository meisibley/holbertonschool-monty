#include "monty.h"

/**
 * free_stack - free stacks
 * @stack: a doubly linked list
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (!stack)
		return;
	temp = stack;
	while (1)
	{
		temp = stack->next;
		free(stack);
		if (!temp)
			return;
		stack = temp->next;
		free(temp);
		if (!stack)
			return;
	}
}
