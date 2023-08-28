#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the input.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the input.
 */
void add(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        sum = (*stack)->n + (*stack)->next->n;
        pop(stack, line_number);
        (*stack)->n = sum;
}
/**
 * sub - sub the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the input.
 */
void sub(stack_t  **stack, unsigned int line_number)
{
	int subt;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	}

	subt = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = subt;
}
