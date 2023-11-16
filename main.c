#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opnFile(argv[1]);
	freeNode();
	return (0);
}

/**
 * crtNode - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *crtNode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err_handle(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freeNode - Frees nodes in the stack.
 */
void freeNode(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * addQueue - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void addQueue(stack_t **newNode, __attribute__((unused))unsigned int ln)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *newNode;
	(*newNode)->prev = temp;

}
