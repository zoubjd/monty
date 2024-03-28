#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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


void execute(char **command);
/*check for error*/
void check_argc(int argc);
void check_monty(FILE *monty, char *file_name);
void malloc_error(void);
void line_error(int line_num, char *command);

/*string*/
int _strlen(const char *s);
char **tokens(FILE *file);
char _strcmp(const char *str1, const char *str2);
int _round(double number);
int my_isdigit(int c);
char *_itoa(int n);
char *_strchr(const char *p, int ch);
char *_strdup(const char *str);
void reverse_string(char *buf, int len);
int is_whole_number(const char *str);

/*execute*/
stack_t *add_node(stack_t **head, const int n);
void print(const stack_t *h);


#endif
