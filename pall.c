#include "monty.h"

/**
* print_all_values - prints all values when pall opcode is encountered
* @stack: the stack to be printed
* @line_number: unused parameter
*/

void print_all_values(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
