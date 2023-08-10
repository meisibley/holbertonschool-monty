#include "monty.h"

/**
 * executfc - execute all those functions
 * @line_buf: a line reading in the monty file
 * @count: line number of the monty file
 *
 * Return: nothing
 */
void executfc(char *line_buf, unsigned int count, stack_t **stack)
{
	char *op = NULL, *value = NULL;
	int i = 0, j = 0, k = 0, flag = 0;
	instruction_t instr[] = {
		{"push", func_push},
		{"pall", func_pall},
		{NULL, NULL}
	};

	if (line_buf == NULL)
		exit(EXIT_SUCCESS);
	while (line_buf[i] == ' ' || line_buf[i] == '\t')
		i++;
	while (line_buf[i] != ' ' && line_buf[i] != '\t')
	{
		op[j] = line_buf[i];
		i++, j++;
	}
	while (line_buf[i] == ' ' || line_buf[i] == '\t')
		i++;
	while (line_buf[i] != ' ' && line_buf[i] != '\t' && line_buf[i] != '\0')
	{value[k] = line_buf[i];
		k++, i++;
	}
	intvalue = handle_value(value, k, count);
	i = 0;
	while (instr[i].opcode != NULL)
	{
		if (strcmp(op, instr[i].opcode) == 0)
		{
			instr[i].f(stack, count);
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0) /*op is not in the opcode pool*/
		fprintf(stderr, "L%u: unknown instruction %s\n", count, op);
	free(line_buf);
}

/**
 * value_handler - check new node integer value avaliable
 * @value: a character or string, each value between ASCII 48 and 57
 * @k: length of string value
 * @count: monty file line count
 *
 * Return: nothing
 */
int handle_value(char *value, int k, unsigned int count)
{
	int i, n = 0, neg = 1, flag = 0;

	if (value[0] == '-')
		neg = -1;
	if (value)
	{
		for (i = 0; i < k; i++)
		{
			if (value[i] < 48 || value[i] > 57)
				flag = 1;
		}
		if (flag == 0)
			n = atoi(value);
		else
		{
			fprintf(stderr, "L%u: usage: push integer", count);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer", count);
		exit(EXIT_FAILURE);
	}
	return (n * neg);
}

/**
 * func_push - push a node into a stack
 * @node: pushed stack node
 * @count: monty file line number
 *
 * Return: nothing
 */
void func_push(stack_t **stack, unsigned int count)
{
	stack_t *temp = NULL, *new_node = NULL;

	(void)count;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = intvalue;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		temp = *stack;
		new_node->next = temp;
		temp->prev = new_node;
		*stack = new_node;
	}
	free(temp), free(new_node);
}

/**
 * func_pall - pull nodes one by one and print out
 * @node: pulled stack node
 * @count: monty file line number
 *
 * Return: nothing
 */
void func_pall(stack_t **stack, unsigned int count)
{
	stack_t *node;

	(void)count;
	node = *stack;
	while(node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
