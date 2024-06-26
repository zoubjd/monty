#include "monty.h"

/**
 * _division - divises the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _division(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
	
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack) = (*stack)->next;
    result = (*stack)->n / (*stack)->prev->n;
    (*stack)->n = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;


}


/**
 * _multip - multis the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _multip(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack) = (*stack)->next;
    sum = (*stack)->n * (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;


}


/**
 * _mod - gives the excess of the div the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
	
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack) = (*stack)->next;
    result = (*stack)->n % (*stack)->prev->n;
    (*stack)->n = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;


}

/**
 * pchar - gives the excess of the div the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int number;

	if (stack == NULL || *stack == NULL)
    {
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    number = (*stack)->n;
    
    if (number < 0 || number > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", number);


}

/**
 * pstr - prints a string
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int number;
	stack_t *temp;
    (void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		number = temp->n;
		if (number <= 0 || number > 127)
			break;
		printf("%c", number);
		temp = temp->next;
	}
	printf("\n");
    }


