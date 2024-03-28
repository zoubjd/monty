#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * print - check code
 * Description: prints doubly linked lists
 *
 * @h: the head of the list
 */

void print(const stack_t *h)
{

if (h != NULL)
{
while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
}
}
}
