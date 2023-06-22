#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to stack
 * @line_number: Line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int i;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = i;
	/*insert_dnodeint_at_index(stack, 1, i);*/
}

/**
 * add - subtracts the top element of the stack
 * @stack: Pointer to stack
 * @line_number: Line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 1))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack);
}

/**
 * sub - Adds the top two elements of the stack
 * @stack: Pointer to stack
 * @line_number: Line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 1))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack);
}

/**
 * div - Divides the second top element of the stack by the top element
 * @stack: Pointer to stack
 * @line_number: Line number in the file
 *
 * Return: Exit status
 */
void divide(stack_t **stack, unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 1))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack);
}
