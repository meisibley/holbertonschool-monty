#include "monty.h"

/**
 * handle_value - check new node integer value avaliable
 * @value: a character or string, each value between ASCII 48 and 57
 * @k: length of string value
 * @count: monty file line count
 *
 * Return: a integer value
 */
int handle_value(char *value, unsigned int count)
{
	int i, n = 0, neg = 1, flag = 0;

	if (value[0] == '-')
		neg = -1;
	if (value != NULL)
	{
		for (i = 0; i < (int)strlen(value) - 1; i++)
		{
			if (value[i] < 48 || value[i] > 57)
				flag = 1;
		}
		if (flag == 0)
			n = atoi(value);
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
	return (n * neg);
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

/**
 * func_pint - pull the top node and print out value
 * @node: pulled stack node
 * @count: monty file line number
 *
 * Return: nothing
 */
void func_pint(stack_t **stack, unsigned int count)
{
	stack_t *node;

	(void)count;
	node = *stack;
	if (node == NULL)
		return;
	printf("%d\n", node->n);
}
