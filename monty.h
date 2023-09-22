#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
int func_parse_line(char *buffer, int line_number, int format);
void func_read_file(FILE *);
int len_chars(FILE *);
void lookFor_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_the_node(int n);
void func_free_nodes(void);
void print_all_stack(stack_t **, unsigned int);
void push_to_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void call_func(op_func, char *, char *, int, int);

void func_print_top(stack_t **, unsigned int);
void func_pop_top(stack_t **, unsigned int);
void func_nop(stack_t **, unsigned int);
void func_swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void func_add_nodes(stack_t **, unsigned int);
void func_sub_nodes(stack_t **, unsigned int);
void func_div_nodes(stack_t **, unsigned int);
void func_mul_nodes(stack_t **, unsigned int);
void func_mod_nodes(stack_t **, unsigned int);

/*String operations*/
void func_print_char(stack_t **, unsigned int);
void func_print_str(stack_t **, unsigned int);
void func_rotl(stack_t **, unsigned int);

/*Error hanlding*/
void first_err(int error_code, ...);
void second_err(int error_code, ...);
void third_err(int error_code, ...);
void func_string_err(int error_code, ...);
void func_rotr(stack_t **, unsigned int);
void handleInvalidArg(void);
#endif
