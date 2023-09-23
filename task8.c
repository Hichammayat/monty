#include "monty.h"
/**
 * func_mul_nodes - multiplies.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void func_mul_nodes(stack_t **stack, unsigned int line_number)
{
	int summ;

	if (!stack || !*stack || (*stack)->next == NULL)
		third_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	summ = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
