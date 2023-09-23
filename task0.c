#include "monty.h"
/**
 * push_to_stack - push a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tp;

	if (!head)
	{
		head = *new_node;
		return;
	}
	if (!new_node || !*new_node)
		exit(EXIT_FAILURE);
	tp = head;
	head = *new_node;
	head->next = tp;
	tp->prev = head;
}

/**
 * print_all_stack - print all the element of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_all_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tp;

	(void) line_number;
	if (!stack)
		exit(EXIT_FAILURE);
	tp = *stack;
	while (tp != NULL)
	{
		printf("%d\n", tp->n);
		tp = tp->next;
	}
}
