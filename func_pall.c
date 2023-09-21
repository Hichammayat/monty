#include "monty.h"
/**
 * func_pall - prints the stack
 * @head: stack head
 * @count: not used
 * Return: no return
*/
void func_pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
