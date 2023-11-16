#include "monty.h"


/**
 * addStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void addStack(stack_t **newNode, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	temp = head;
	head = *newNode;
	head->next = temp;
	temp->prev = head;
}


/**
 * prtStack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: line number of  the opcode.
 */
void prtStack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_out - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void pop_out(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		moreError(7, lineNumber);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * prtTop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void prtTop(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		moreError(6, lineNumber);
	printf("%d\n", (*stack)->n);
}
