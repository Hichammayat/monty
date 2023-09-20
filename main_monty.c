#include "monty.h"
bus_T bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	unsigned int count = 0;
	stack_t *stack = NULL;
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t line = 1;

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
	while (read_line > 0)
	{
		content = NULL;
		line = getline(&content, &size, file);
		bus.content = content;
		count++;
		if (line > 0)
		{
			execute(content, &stack, count, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
