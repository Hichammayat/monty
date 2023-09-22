#include "monty.h"

/**
 * func_print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void func_print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asc;
	stack_t *tp;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}

	tp = *stack;
	while (tp)
	{
		asc = tp->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		tp = tp->next;
	}
	printf("\n");
}
