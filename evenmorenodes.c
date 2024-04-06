#include "monty.h"

/**
 * div - divises the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
	

    (*stack) = (*stack)->next;
    result = (*stack)->n / (*stack)->prev->n;
    (*stack)->n = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;


}

