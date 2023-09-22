#include "monty.h"

/**
 * func_rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void func_rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tp;

	if (!stack || !*stack || (*stack)->next == NULL)
		return;

	tp = *stack;

	while (tp->next != NULL)
		tp = tp->next;

	tp->next = *stack;
	tp->prev->next = NULL;
	tp->prev = NULL;
	(*stack)->prev = tp;
	(*stack) = tp;
}
