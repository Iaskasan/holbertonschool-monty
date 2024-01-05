#include "monty.h"

/**
* process_file - open and read a file (file_name)
* @file_name: the name of the file to be opened
* Return: an int
*/

int process_file(const char *file_name)
{
	int status = 0;
	FILE *file = NULL;

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		return (EXIT_FAILURE);
	}
	status = read_and_process(file);

	fclose(file);
	return (status);
}

/**
* read_and_process - read a file, find opcodes and execute the
* corresponding functions
* @file: the file to be read
* Return: an int
*/

int read_and_process(FILE *file)
{
	char line[2048];
	int line_number = 0;
	char *opcode = NULL;
	bool found;
	int i;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
	{"push", push_element},
	{"pall", print_all_values},
	{NULL, NULL}
};

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode == NULL)
			continue;

		found = false;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				found = true;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free(stack);
			return (EXIT_FAILURE);
		}
	}
	free(stack);
	return (EXIT_SUCCESS);
}
