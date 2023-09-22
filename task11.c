#include "monty.h"

/**
 * func_print_char - prints the char at the top of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void func_print_char(stack_t **stack, unsigned int line_number)
{
	int asc;

	if (stack == NULL || *stack == NULL)
		func_string_err(11, line_number);

	asc = (*stack)->n;
	if (asc < 0 || asc > 127)
		func_string_err(10, line_number);
	printf("%c\n", asc);
}
