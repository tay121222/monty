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

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 0))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = get_dnodeint_at_index(*stack, 0);

	while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
