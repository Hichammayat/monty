#include "monty.h"
/**
* free_the_stack - frees the stack
* @head: pointer to the head of the stack
*/
void free_the_stack(stack_t *head)
{
	stack_t *tp;

	tp = head;
	while (head)
	{
		tp = head->next;
		free(head);
		head = tp;
	}
}
