#include "monty.h"
/**
 * func_pint - prints the top element
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void func_pint(stack_t **head, unsigned int count)
{
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
