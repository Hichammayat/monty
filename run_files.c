#include "monty.h"

/**
 * func_read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
i */

void func_read_file(FILE *fd)
{
	int line_num, format = 0;
	char *buff = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buff, &len, fd) != -1; line_num++)
	{
		format = parse_line(buff, line_num, format);
	}
	free(buff);
}

/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int func_parse_line(char *buff, int line_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		err(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	lookFor_func(opcode, value, line_num, format);
	return (format);
}

/**
 * lookFor_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void lookFor_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_to_stack},
		{"pall", print_all_stack},
		{"pint", func_print_top},
		{"pop", func_pop_top},
		{"nop", func_nop},
		{"swap", func_swap_nodes},
		{"add", func_add_nodes},
		{"sub", func_sub_nodes},
		{"div", func_div_nodes},
		{"mul", func_mul_nodes},
		{"mod", func_mod_nodes},
		{"pchar", func_print_char},
		{"pstr", func_print_str},
		{"rotl", func_rotl},
		{"rotr", func_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}

/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
