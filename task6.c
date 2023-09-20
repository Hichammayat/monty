#include "monty.h"
/**
  *func_sub - subtracts the top element of the stack
  *@head: stack head
  *@count: line_number
  *Return: nothing
 */
void func_sub(stack_t **head, unsigned int count)
{
	stack_t *tp;
	int sus;
	int i;

	tp = *head;
	for (i = 0; tp != NULL; i++)
		tp = tp->next;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head;
	sus = tp->next->n - tp->n;
	tp->next->n = sus;
	*head = tp->next;
	free(tp);
}
