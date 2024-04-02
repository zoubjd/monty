#include "monty.h"

/**
 * check_monty - function checks the file
 * @monty: the file to be checked.
 * @file_name: the name of the file
*/

void check_monty(FILE *monty, char *file_name)
{
if (monty == NULL || file_name == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", file_name);
exit(EXIT_FAILURE);
}
}


/**
 * malloc_error - function checks the file
*/

void malloc_error(void)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

/**
 * line_error - prints an error
 * @line_num: the line number
 * @command: the command
*/

void line_error(int line_num, char *command)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_num, command);
exit(EXIT_FAILURE);
}


/**
 * value_error - prints an error
 * @line: the line number
*/
void value_error(int line)
{
fprintf(stderr, "L%d: usage: push integer\n", line);
exit(EXIT_FAILURE);
}
