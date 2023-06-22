#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to stack
 * @line_number: Line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = pop(stack);
	insert_dnodeint_at_index(stack, 1, i);
}
