#include "monty.h"

/**
 * multiNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void multiNodes(stack_t **stack, unsigned int line_number)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreError(8, line_number, "mul");

	(*stack) = (*stack)->next;
	total = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * modNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void modNodes(stack_t **stack, unsigned int line_number)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		moreError(8, line_number, "mod");


	if ((*stack)->n == 0)
		moreError(9, line_number);
	(*stack) = (*stack)->next;
	total = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
