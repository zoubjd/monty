#include "monty.h"

/**
 * execute - function executes the commands
 * @command: the commands
*/

void execute(char **command)
{
stack_t *head = NULL;
int i = 0;
int line_num;
int digit;

while (command[i] != NULL)
{
if (_strcmp(command[i], "push") == 0 && command[i + 1] != NULL)
{
if (is_whole_number(command[i + 1]))
{
digit = atoi(command[i + 1]);
add_node(&head, digit);
i++;
}
else
{
line_num = _round(i / 2);
line_error(line_num, command[i]);
return;
}
}
else if (_strcmp(command[i], "pall") == 0)
{
print(head);
}
else
{
line_num = _round(i / 2);
line_error(line_num, command[i]);
return;
}
i++;
}
}

