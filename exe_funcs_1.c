#include "monty.h"

/**
 * handle_value - check new node integer value avaliable
 * @value: a character or string, each value between ASCII 48 and 57
 * @count: monty file line count
 *
 * Return: a integer value
 */
int handle_value(char *value, unsigned int count)
{
	int i = 0, n = 0, flag = 0;

	if (value != NULL)
	{
		if (value[0] == '-')
			i = 1;
		for (; i <= (int)strlen(value) - 1; i++)
		{
			if (value[i] < 48 || value[i] > 57)
				flag = 1;
		}
		if (flag == 0)
		{
			n = atoi(value);
		}
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
	return (n);
}

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
	while (stack->prev != NULL)
		stack = stack->prev;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	free(temp);
}

/**
 * func_pint - pull the top node and print out value
 * @stack: pulled stack node
 * @count: monty file line number
 *
 * Return: nothing
 */
void func_pint(stack_t **stack, unsigned int count)
{
	stack_t *node;

	node = *stack;
	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", node->n);
}

/**
 * func_pop - removes the top element of the stack
 * @stack: removes the top node of the stack
 * @count: monty file line number
 *
 * Return: nothing
 */
void func_pop(stack_t **stack, unsigned int count)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->next == NULL)
		*stack = NULL;
	else
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
	}
	free(temp);
}

/**
 * func_swap - swaps the top two elements of the stack
 * @stack: swaps the top two elements of the stack
 * @count: monty file line number
 *
 * Return: nothing
 */
void func_swap(stack_t **stack, unsigned int count)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
