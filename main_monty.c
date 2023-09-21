#include "monty.h"
#include <stdio.h>
#define MAX_LINE_LENGTH 256
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	process_lines(file, &stack);
	free_the_stack(stack);
	fclose(file);
return (0);
}
/**
 * process_lines - exécute le traitement de chaque ligne
 * @file: Pointer to the Monty bytecode file.
 * @stack: Pointer to the stack data structure.
 * Return: nothing
 */
void process_lines(FILE *file, stack_t **stack)
{
	char line[MAX_LINE_LENGTH];
	unsigned int count = 0;
	size_t line_length = strlen(line);

	while (fgets(line, sizeof(line), file) != NULL)
	{
		bus.content = line;
		count++;

		if (line_length > 0 && line[line_length - 1] == '\n')
		{
			line[line_length - 1] = '\0';
		}

		fun_execute(line, stack, count, file);
	}
}
