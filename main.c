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
char **real_command = NULL;
int i;

check_argc(argc);

monty = fopen(argv[1], "r");
check_monty(monty, argv[1]);

command = tokens(monty);
if (command == NULL)
{
fclose(monty);
return (EXIT_FAILURE);
}

for (i = 0; command[i]; i++)
{
real_command = real_tokens(command[i]);
if (real_command == NULL)
{
fclose(monty);
return (EXIT_FAILURE);
}
execute(real_command, (i + 1));
}

fclose(monty);
free(command);


return (EXIT_SUCCESS);

}
