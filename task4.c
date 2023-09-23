#include "monty.h"
/**
 * func_add_nodes - ajouter un element.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void func_add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !*stack || (*stack)->next == NULL)
		third_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
