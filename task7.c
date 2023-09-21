#include "monty.h"
/**
 * func_div - divides second top element of the stack by the top element
 * @head: stack head
 * @count: line number
 * Return: nothing
*/
void func_div(stack_t **head, unsigned int count)
{
	stack_t *h;
	int i = 0;
	int tp;

	h = *head;
	while (h)
	{
		h = h->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	tp = h->next->n / h->n;
	h->next->n = tp;
	*head = h->next;
	free(h);
}
