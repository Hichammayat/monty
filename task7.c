#include "monty.h"
/**
 * func_div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void func_div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if ((*stack)->n == 0)
		third_err(9, line_number);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		third_err(8, line_number, "div");

	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
