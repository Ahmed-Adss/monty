#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


void opnFile(char *file_N);
int parsline(char *buffer, int line_no, int format);
void rdFile(FILE *fd);
int len_chars(FILE *);
void findFunction(char *, char *, int, int);


stack_t *crtNode(int n);
void freeNode(void);
void prtStack(stack_t **, unsigned int);
void addStack(stack_t **, unsigned int);
void addQueue(stack_t **, unsigned int);

void callFunction(op_func, char *, char *, int, int);

void prtTop(stack_t **, unsigned int);
void pop_out(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swapNodes(stack_t **, unsigned int);


void addNodes(stack_t **, unsigned int);
void subNodes(stack_t **, unsigned int);
void divideNodes(stack_t **, unsigned int);
void multiNodes(stack_t **, unsigned int);
void modNodes(stack_t **, unsigned int);


void prtChar(stack_t **, unsigned int);
void prtString(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);


void err_handle(int err_cde, ...);
void moreError(int err_cde, ...);
void stringError(int err_cde, ...);
void rotr(stack_t **, unsigned int);

#endif
