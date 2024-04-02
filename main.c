#include "monty.h"
stack_t *head = NULL;

/**
 * main - check code
 * description: the mai func
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
FILE *monty = fopen(argv[1], "r");
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

check_monty(monty, argv[1]);
read_file(monty);
free_nodes();
fclose(monty);
return (0);

}

/**
 * read_file - reads a file
 * @file: the monty file
 * Return: void
 */

void read_file(FILE *file)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, file) != -1; line_number++)
	{
		format = tokenize_line(buffer, line_number, format);
	}
	free(buffer);
}

