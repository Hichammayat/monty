#include "monty.h"

/**
 * func_rotl - Rotate the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void func_rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tp;

	if (!stack || !*stack || (*stack)->next == NULL)
		return;

	tp = *stack;
	while (tp->next != NULL)
		tp = tp->next;

	tp->next = *stack;
	(*stack)->prev = tp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
