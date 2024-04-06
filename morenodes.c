#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the opcode.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    *stack = temp->next;

    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }

    free(temp);
}


/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
	

    (*stack) = (*stack)->next;
    sum = (*stack)->n + (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;


}

