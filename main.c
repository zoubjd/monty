#include "monty.h"

/**
 * main - function checks the file
 * @argc: the number of cm
 * @argv: the command line arguments
 * Return: 0
*/

int main(int argc, char *argv[])
{
FILE *monty;
char **command = NULL;

check_argc(argc);

monty = fopen(argv[1], "r");
check_monty(monty, argv[1]);

command = tokens(monty);
if (command == NULL)
{
fclose(monty);
return (EXIT_FAILURE);
}
execute(command);

fclose(monty);
free(command);

return (EXIT_SUCCESS);

}
