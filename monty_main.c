#include "monty.h"
/**
 * main - main function
 * Return: 0
 */
int main(void)
{
	stack_t *stack = NULL;
	char line[100];
	unsigned int line_number = 1;

	while (fgets(line, sizeof(line), stdin) != NULL)
	{
		char *opcode = strtok(line, " \n");

		if (opcode == NULL)
		{
			line_number++;
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		line_number++;
	}
	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;

		free(temp);
	}

	return (0);
}
