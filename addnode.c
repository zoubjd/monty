#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * add_node - check code
 * Description: adds a new node in the head
 *
 * @head: the head of the list
 * @n: content of the node
 *
 * Return: the new node
 */

stack_t *add_node(stack_t **head, const int n)
{
stack_t *new = malloc(sizeof(stack_t));

if (head == NULL)
{
malloc_error();
return (NULL);
}
if (new == NULL)
{
malloc_error();
return (NULL);
}

new->n = n;
new->prev = NULL;
new->next = *head;
if (*head != NULL)
{
(*head)->prev = new;
}
*head = new;

return (new);
}
