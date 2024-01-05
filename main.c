#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: returns the program's execution status (0 if success)
 */

int main(int argc, char **argv)
{
	int status;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	status = process_file(argv[1]);

	return (status);
}
