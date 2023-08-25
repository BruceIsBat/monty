#include "monty.h"
/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the input.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument = strtok(NULL, " ");
	int value;
	stack_t *new_node;

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
	fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
	}
	new_node->n = value;

	new_node->prev = NULL;
 	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
 	}

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the input.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
