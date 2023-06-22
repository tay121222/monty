#include "monty.h"

/**
 * mod - computes the rest of the div of the second top element of the stack
 * @stack: Pointer to stack
 * @line_number: Line number in the file
 *
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 1))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack);
}
