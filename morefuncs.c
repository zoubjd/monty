#include "monty.h"

/**
 * is_whole_number - round function
 * @str: the digit to be checked
 * Return: 1 in case of failure or 0
*/
int is_whole_number(const char *str)
{
while (*str)
{
if (!my_isdigit(*str))
{
return (0);
}
str++;
}
return (1);
}

