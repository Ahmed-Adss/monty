#include "monty.h"

/**
 * opnFile - opens a file
 * @file_N: the file namepath
 * Return: void
 */

void opnFile(char *file_N)
{
	FILE *fd = fopen(file_N, "r");

	if (file_N == NULL || fd == NULL)
		err_handle(2, file_N);

	rdFile(fd);
	fclose(fd);
}


/**
 * rdFile - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void rdFile(FILE *fd)
{
	int line_no, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_no = 1; getline(&buffer, &length, fd) != -1; line_no++)
	{
		format = parsline(buffer, line_no, format);
	}
	free(buffer);
}


/**
 * parsline - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_no: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parsline(char *buffer, int line_no, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		err_handle(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findFunction(opcode, val, line_no, format);
	return (format);
}

/**
 * findFunction - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void findFunction(char *opcode, char *val, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", addStack},
		{"pall", prtStack},
		{"pint", prtTop},
		{"pop", pop_out},
		{"nop", nop},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divideNodes},
		{"mul", multiNodes},
		{"mod", modNodes},
		{"pchar", prtChar},
		{"pstr", prtString},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			callFunction(func_list[i].f, opcode, val, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err_handle(3, ln, opcode);
}


/**
 * callFunction - Calls the required function.
 * @function: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric val.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void callFunction(op_func function, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err_handle(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err_handle(5, ln);
		}
		node = crtNode(atoi(val) * flag);
		if (format == 0)
			function(&node, ln);
		if (format == 1)
			addQueue(&node, ln);
	}
	else
		function(&head, ln);
}
