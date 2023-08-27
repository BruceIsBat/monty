#include "monty.h"
/**
 * main - main function
 * Return: 0
 */
int main(int argc, char *argv[])
{

	FILE *file;
	stack_t *stack = NULL;
	char line[100];
	unsigned int line_number = 1;
	file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
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
			fclose(file);
			exit(EXIT_FAILURE);
		}

		line_number++;
	}
	fclose(file);

	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;

		free(temp);
	}

	return (0);
}
