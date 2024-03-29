#include "monty.h"

/**
 * execute - function executes the commands
 * @command: the commands
 * @line: the current line in the file
*/

void execute(char **command, int line)
{
stack_t *head = NULL;
int i = 0;
int line_num;
int digit;


if (_strcmp(command[0], "push") == 0 && command[1] != NULL)
{
if (is_whole_number(command[1]))
{
digit = atoi(command[1]);
add_node(&head, digit);
}
else
{
line_num = line;
line_error(line_num, command[i]);
return;
}
}
else if (_strcmp(command[0], "pall") == 0)
{
print(head);
}
else
{
line_num = line;
line_error(line_num, command[0]);
return;
}

}

