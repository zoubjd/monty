#include "monty.h"

/**
 * pop - Adds a node to the queue.
 * @stack: Pointer to the head.
 * @line_number: line number of the opcode.
 */
void pop(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
temp = head;

if (temp->next != NULL)
{
temp->next = temp->next->next;
free(temp->next->prev);
temp->next->prev = temp;
}
else
{
free(temp->next);
temp->next = NULL;
}

}


