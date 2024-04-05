#include "monty.h"

/**
 * pint - Adds a node to the queue.
 * @stack: Pointer to the head.
 * @ln: line number of the opcode.
 */
void pop(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

	if (head == NULL)
	{
		fprintf(stderr ,"L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);

	}
    tmp = head;

    tmp->next->prev = NULL;
    head = tmp->next;
    free(tmp);

}


