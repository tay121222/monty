#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Array of arguments
 * Return: Exit status
 */
int main(int argc, char *argv[])
{
	const char *file_path = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file_path = argv[1];
	return (interpret_file(file_path));
}
