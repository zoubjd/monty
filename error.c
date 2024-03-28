#include "monty.h"

/**
 * check_monty - function checks the file
 * @monty: the file to be checked.
 * @file_name: the name of the file
*/

void check_monty(FILE *monty, char *file_name)
{
if (monty == NULL)
{
char *message = "Error: Can't open file";
write(STDERR_FILENO, message, _strlen(message));
write(STDERR_FILENO, file_name, _strlen(file_name));
write(STDERR_FILENO, "\n", 1);
exit(EXIT_FAILURE);
}
}

/**
 * check_argc - function checks the file
 * @argc: the number of cm arguments
*/

void check_argc(int argc)
{
if (argc != 2)
{
char *message = "USAGE: monty file\n";
write(STDERR_FILENO, message, _strlen(message));
exit(EXIT_FAILURE);
}
}

/**
 * malloc_error - function checks the file
*/

void malloc_error(void)
{
char *message = "Error: malloc failed\n";
write(STDERR_FILENO, message, _strlen(message));
exit(EXIT_FAILURE);
}

/**
 * line_error - prints an error
 * @line_num: the line number
 * @command: the command
*/

void line_error(int line_num, char *command)
{
char *num = _itoa(line_num + 1);
char *message = ": unknown instruction ";
write(STDERR_FILENO, "L", 1);
write(STDERR_FILENO, num, _strlen(num));
write(STDERR_FILENO, message, _strlen(message));
write(STDERR_FILENO, command, _strlen(command));
write(STDERR_FILENO, "\n", 1);
exit(EXIT_FAILURE);
}
