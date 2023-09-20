#include "monty.h"
/**
 * func_pop - returns the top element
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void func_pop(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
