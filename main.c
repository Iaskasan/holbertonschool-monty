#include "monty.h"

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
