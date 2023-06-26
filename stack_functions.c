#include "monty.h"

/**
 * push - Push element to the stack
 * @stack: Pointer to stack
 * @value: Value to be pushed
 *
 * Return: 1 or 0
 */
int push(stack_t **stack, int value)
{
	if (mode == MODE_QUEUE)
		return (!!add_dnodeint_end(stack, value));
	return (!!add_dnodeint(stack, value));
}

/**
 * pall - Prints values on the stack
 * @stack: Pointer to stack
 */
void pall(stack_t **stack)
{
	print_dlistint(*stack);
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to stack
 * @line_number: Line number in the file
 *
 * Return: Exit status
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 0))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to stack
 * @line_number: Line number in the file
 *
 * Return: Exit status
 */
void pop_code(stack_t **stack, unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 0))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack);
}

/**
 * pop - pops node from stack
 * @head: pointer to first node
 * Return: n
 */
int pop(stack_t **head)
{
	stack_t *node = get_dnodeint_at_index(*head, 0);
	int i = 0;

	i = node->n;
	delete_dnodeint_at_index(head, 0);
	return (i);
}
