#include "monty.h"

/**
 * tokenize - parse tokens from a reading file line
 * @line_buf: a line reading in the monty file
 * @count: line number of the monty file
 * @stack: doubly linked list stores pushed values
 *
 * Return: nothing
 */
void tokenize(char *line_buf, unsigned int count, stack_t **stack)
{
	char *op = NULL, *value = NULL, *token = NULL;
	const char *delim = " \n\t";
	int i = 0;

	token = strtok(line_buf, delim);
	while (token != NULL)
	{
		if (i == 0)
			op = strdup(token);
		if (i == 1)
			value = strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	if (i > 0)
		exe_opcode(op, value, count, stack);
	free(token);
}

/**
 * exe_opcode - find match opcode and execute match func
 * @op: opcode
 * @value: new node value
 * @count: monty file line number
 * @stack: doubly linked list stores pushed values
 *
 * Return: nothing
 */
void exe_opcode(char *op, char *value, unsigned int count, stack_t **stack)
{
	int i = 0, j = 1, k = 1, flag = 0;
	instruction_t instr[] = {
		{"push", func_push}, {"pall", func_pall}, {"pint", func_pint},
		{"pop", func_pop}, {"swap", func_swap}, {"add", func_add},
		{"nop", func_nop}, {NULL, NULL}
	};

	if (strncmp(op, "push", strlen(op)) == 0)
	{
		if (!value)
		{fprintf(stderr, "L%u: usage: push integer\n", count);
			exit(EXIT_FAILURE);
		}
		else
			intvalue = handle_value(value, count);
	}
	else
	{
		while (instr[j].opcode != NULL && k != 0)
			k = strncmp(op, instr[j].opcode, strlen(op)), j++;
		if (k != 0)
		{fprintf(stderr, "L%u: unknown instruction %s\n", count, op);
			exit(EXIT_FAILURE);
		}
	}
	while (instr[i].opcode != NULL)
	{
		if (strncmp(op, instr[i].opcode, strlen(instr[i].opcode)) == 0)
		{instr[i].f(stack, count);
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0) /*op is not in the opcode pool*/
	{fprintf(stderr, "L%u: unknown instruction %s\n", count, op);
		exit(EXIT_FAILURE);
	}
	free(op), free(value);
}

/**
 * func_push - push a new node to stack from beginning
 * @count: monty file line number
 * @stack: doubly linked list stores pushed values
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
		new_node->next->prev = new_node;
		*stack = new_node;
	}
}

/**
 * func_pall - pull nodes one by one and print out
 * @count: monty file line number
 * @stack: doubly linked list stores pushed values
 *
 * Return: nothing
 */
void func_pall(stack_t **stack, unsigned int count)
{
	stack_t *node;
	(void)count;

	node = *stack;
	if (node == NULL)
		return;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
