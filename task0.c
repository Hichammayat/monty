#include "monty.h"
/**
 * func_push - add node to the stack
 * @head: pointer to the stack head
 * @count: line_number
 * Return: no return
*/
void func_push(stack_t **head, unsigned int count)
{
	int flag = 0;
	int n, K = 0;

	if (bus.arg != NULL)
	{
		if (bus.arg[0] == '-')
			K++;
		for (; bus.arg[K] != '\0'; j++)
		{
			if (bus.arg[k] > 57 || bus.arg[k] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
/**
 * func_pall - prints the element of the stack
 * @head: stack head
 * @count: cast to void
 * Return: nothing
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
