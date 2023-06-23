#include "monty.h"

/**
 * rtrim - Removes trailing characters from a string
 * @str: Pointer to the string
 * @chars: Characters to be removed
 *
 * Return: Pointer to the trimmed string
 */
char *rtrim(char *str, const char *chars)
{
	int i;

	i = strlen(str) - 1;
	while (i >= 0 && strchr(chars, str[i]) != NULL)
		i--;

	str[i + 1] = '\0';

	return (str);
}

/**
 * is_integer - Checks if a string represents a valid integer
 * @str: String to check
 * Return: True if the string is a valid integer, otherwise false
 */
bool is_integer(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (false);

	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

/**
 * rotl - Rotates the stack to the top
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *last, *second_last;

	if (!get_dnodeint_at_index(*stack, 1))
		return;

	last = *stack;
	second_last = last->next;

	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = second_last;
	(*stack)->prev = NULL;

	last->next->next = NULL;
}

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *last, *second_last;

	if (!get_dnodeint_at_index(*stack, 1))
		return;
	last = *stack;
	second_last = last->next;

	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
