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

/*nodes*/
stack_t *create_node(int n);
void free_nodes(void);
void add_node(stack_t **new_node, __attribute__((unused))unsigned int ln);
void print(stack_t **stack, unsigned int line_number);
int tokenize_line(char *buffer, int line_number, int format);
void pint(__attribute__((unused))stack_t **stack, unsigned int line_number);
void pop(__attribute__((unused))stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _division(stack_t **stack, unsigned int line_number);
void _multip(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/*file*/
void read_file(FILE *file);

/*errors*/
void check_monty(FILE *monty, char *file_name);
void malloc_error(void);
void line_error(int line_num, char *command);
void value_error(int line);

/*execute*/
void find_func(char *opcode, char *value, int ln, int format);
void call_fun(op_func func, char *op, char *val, int ln, int format);


#endif

