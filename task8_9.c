#include "monty.h"
/**
 * func_mul - multiplies second top element of the stack with the top element
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void func_mul(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tp = h->next->n * h->n;
	h->next->n = tp;
	*head = h->next;
	free(h);
}

/**
 * func_mod -  computes the rest of the division of the second top element.
 *
 * @head: stack head
 * @count: line_number
 * Return: nothing
*/
void func_mod(stack_t **head, unsigned int count)
{
	stack_t *h;
	int lenght = 0;
	int tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		lenght++;
	}
	if (lenght < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
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
	tmp = h->next->n % h->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}
