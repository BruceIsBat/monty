#include "monty.h"
/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
    stack_t *stack = NULL;
    char line[100];

    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        char *opcode = strtok(line, " \n");

        if (strcmp(opcode, "push") == 0)
        {
            push(&stack, 0); /* Replace 0 with the actual line number */
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, 0); /* Replace 0 with the actual line number */
        }
        /* Handle other opcodes */
        /* ... */
    }

    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}
