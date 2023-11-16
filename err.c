#include "monty.h"

/**
 * err_handle - Prints appropiate error messages determined by their error code.
 * @err_cde: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void err_handle(int err_cde, ...)
{
	va_list arg_ment;
	char *op_eration;
	int line_no;

	va_start(arg_ment, err_cde);
	switch (err_cde)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg_ment, char *));
			break;
		case 3:
			line_no = va_arg(arg_ment, int);
			op_eration = va_arg(arg_ment, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op_eration);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg_ment, int));
			break;
		default:
			break;
	}
	freeNode();
	exit(EXIT_FAILURE);
}

/**
 * moreError - handles errors.
 * @err_cde: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void moreError(int err_cde, ...)
{
	va_list arg_ment;
	char *op_eration;
	int line_no;

	va_start(arg_ment, err_cde);
	switch (err_cde)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg_ment, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg_ment, int));
			break;
		case 8:
			line_no = va_arg(arg_ment, unsigned int);
			op_eration = va_arg(arg_ment, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_no, op_eration);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg_ment, unsigned int));
			break;
		default:
			break;
	}
	freeNode();
	exit(EXIT_FAILURE);
}

/**
 * stringError - handles errors.
 * @err_cde: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void stringError(int err_cde, ...)
{
	va_list arg_ment;
	int line_no;

	va_start(arg_ment, err_cde);
	line_no = va_arg(arg_ment, int);
	switch (err_cde)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
			break;
		default:
			break;
	}
	freeNode();
	exit(EXIT_FAILURE);
}
