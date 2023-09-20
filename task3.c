#include "monty.h"
/**
 * func_swap - adds to  the top two elements of the stack.
 * @head: the stack head
 * @count: line number
 * Return: nothing
*/
void func_swap(stack_t **head, unsigned int count)
{
	stack_t *h;
	int i = 0, tp;

	h = *head;
	while (h)
	{
		h = h->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tp = h->n;
	h->n = h->next->n;
	h->next->n = tp;
}