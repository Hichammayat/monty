#include "monty.h"
stack_t *head = NULL;
/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	FILE *fd = fopen(argv[1], "r");

	if (argc != 2)
	{
		handleInvalidArg();
	}
	if (argv[1] == NULL || fd == NULL)
	{
		first_err(2, argv[1]);
	}
	func_read_file(fd);
	fclose(fd);
	func_free_nodes();
	return (0);
}
/**
 * handleInvalidArg - handle invald argument
 * Return: return nothing
 */

void handleInvalidArg(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
