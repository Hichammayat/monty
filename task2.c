#include "monty.h"
/**
 * func_pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void func_pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tp;

	if (stack == NULL || *stack == NULL)
		third_err(7, line_number);

	tp = *stack;
	*stack = tp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tp);
}
