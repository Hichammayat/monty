#include "monty.h"
/**
 * create_the_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_the_node(int n)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		second_err(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = n;
	return (nd);
}

/**
 * add_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tp;

	if (!new_node || !*new_node )
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tp = head;
	while (tp->next != NULL)
		tp = tp->next;

	tp->next = *new_node;
	(*new_node)->prev = tp;

}
