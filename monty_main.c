#include "monty.h"
/**
 * main - main function
 * @argc: argument count
 * @argv:argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);

	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;

		free(temp);
	}

	return (0);
}
/**
 * read_file - Opens and reads a Monty bytecode file
 * @filename: The name of the bytecode file
 * @stack: Pointer to the stack
 */
void read_file(const char *filename, stack_t **stack)
{
	FILE *file;
	char line[100];
	unsigned int line_number = 1;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
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
			push(stack, line_number);
		else if (strcmp(opcode, "pall") == 0)
			pall(stack, line_number);
		else if (strcmp(opcode, "pint") == 0)
			pint(stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			pop(stack, line_number);
		else if (strcmp(opcode, "swap") == 0)
			swap(stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			exit(EXIT_FAILURE);
		}

		line_number++;
	}
	fclose(file);
}
