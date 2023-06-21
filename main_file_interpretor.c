#include "monty.h"
/**
 * execute_instruction - Executes instruction based on the opcode
 * @stack: Pointer to stack
 * @opcode: Opcode to execute
 * @line_number: Line number in the file
 * @file_path: Path to the file
 * Return: Exit status
 */
int execute_instruction(stack_t **stack, const char *opcode,
		int line_number)
{
	char *token;
	int argument;

	if (strcmp(opcode, "push") == 0)
	{
		token = strtok(NULL, " \t\n");

		if (token == NULL || !isdigit(token[0]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (EXIT_FAILURE);
		}
		argument = atoi(token);

		push(stack, argument);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
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
	int line_number;
	stack_t *stack = NULL;
	char line[100];
	int status;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		return (EXIT_FAILURE);
	}

	line_number = 1;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		char *token = strtok(line, " \t\n");

		if (token == NULL || token[0] == '#')
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

		line_number++;
	}

	fclose(file);
	return (EXIT_SUCCESS);
}
