#include "monty.h"
/**
 * func_push - add node to the stack
 * @head: pointer to the stack head
 * @count: line_number
 * Return: no return
*/
void func_push(stack_t **head, unsigned int count)
{
	int flag = 0, n;
	int K = 0;

	if (bus.arg != NULL)
	{
		if (bus.arg[0] == '-')
			K++;
		for (; bus.arg[K] != '\0'; K++)
		{
			if (bus.arg[K] > 57 || bus.arg[K] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_the_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_the_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
