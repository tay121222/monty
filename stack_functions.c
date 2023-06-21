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
