#include "monty.h"

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		malloc_error();
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_node - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_node(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
if (new_node == NULL || *new_node == NULL)
{
exit(EXIT_FAILURE);
}

if (head == NULL)
{
head = *new_node;
return;
}

(*new_node)->next = head;
head->prev = *new_node;
head = *new_node;
(*new_node)->prev = NULL;

}

/**
 * print - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - Adds a node to the queue.
 * @stack: Pointer to the head.
 * @ln: line number of the opcode.
 */
void pint(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (head == NULL)
		printf("L%d: can't pint, stack empty", line_number);

	while (head != NULL)
	{
		tmp = head;
		printf("%d", tmp->n);
	}

}

