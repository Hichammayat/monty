#include "monty.h"
/**
 * func_swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void func_swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tp;

	if (!stack || !*stack || (*stack)->next == NULL)
		third_err(8, line_number, "swap");
	tp = (*stack)->next;
	(*stack)->next = tp->next;
	if (tp->next != NULL)
		tp->next->prev = *stack;
	tp->next = *stack;
	(*stack)->prev = tp;
	tp->prev = NULL;
	*stack = tp;
}
