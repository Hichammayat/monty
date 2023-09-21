#include "monty.h"
/**
 * func_pchar - prints char at the top of the stack
 * @head: stack head
 * @count: line_number
 * Return: nothing
*/
void func_pchar(stack_t **head, unsigned int count)
{
	stack_t *h;

	h = *head;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
