#include "monty.h"

/**
 * execute_push - Executes the push opcode
 * @stack: Pointer to stack
 * @line_number: Line number in the file
 * Return: Exit status
 */
int execute_push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int argument;

	fflush(stdout);
	token = strtok(NULL, " \r\t\n");
	if (token == NULL || !is_integer(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}
	argument = atoi(token);
	push(stack, argument);
	return (EXIT_SUCCESS);
}

/**
 * execute_instruction - Executes instruction based on the opcode
 * @stack: Pointer to stack
 * @opcode: Opcode to execute
 * @line_number: Line number in the file
 * Return: Exit status
 */
int execute_instruction(stack_t **stack, const char *opcode,
		unsigned int line_number)
{
	if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else if (strcmp(opcode, "push") == 0)
		execute_push(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop_code(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
	{
	}
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		divide(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		mul(stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
		mod(stack, line_number);
	else if (strcmp(opcode, "pchar") == 0)
		pchar(stack, line_number);
	else if (strcmp(opcode, "pstr") == 0)
		pstr(stack, line_number);
	else if (strcmp(opcode, "rotl") == 0)
		rotl(stack, line_number);
	else if (strcmp(opcode, "rotr") == 0)
		rotr(stack, line_number);
	else if (strcmp(opcode, "stack") == 0)
		op_stack(stack, line_number);
	else if (strcmp(opcode, "queue") == 0)
		queue(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 * interpret_file - Interprets the Monty byte code file
 * @file_path: Path to the Monty byte code file
 * Return: Exit status
 */
int interpret_file(const char *file_path)
{
	FILE *file = fopen(file_path, "r");
	int line_number, status;
	stack_t *stack = NULL;
	char line[100];

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		return (EXIT_FAILURE);
	}
	line_number = 1;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		char *token = strtok(line, " \r\t\n");

		if (token != NULL)
		{
			if (token[0] == '#')
			{
				line_number++;
				continue;
			}
			status = execute_instruction(&stack, token, line_number);
			if (status != EXIT_SUCCESS)
			{
				fclose(file);
				return (status);
			}
		}
		line_number++;
	}
	free_dlistint(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
