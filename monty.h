#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct args_s - args, file, line content, flag
 * @args: opcode arguments
 * @file: Pointer to monty file
 * @buffer: line content
 * @queue_flag: Queue mode flag
 * Description: Carries values through the program
 */
typedef struct args_s
{
	char *args;
	FILE *file;
	char *buffer;
	int queue_flag;
}  args_s;

extern args_s args;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int execute(char *buffer, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void _push(stack_t **head, unsigned int counter);
void _pall(stack_t **head, unsigned int counter);
void _addnode(stack_t **head, int n);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
void _pint(stack_t **head, unsigned int counter);
void _pop(stack_t **head, unsigned int counter);
void _swap(stack_t **head, unsigned int counter);
void _add(stack_t **head, unsigned int counter);
void _nop(stack_t **head, unsigned int counter);
void _sub(stack_t **head, unsigned int counter);
void _div(stack_t **head, unsigned int counter);
void _mul(stack_t **head, unsigned int counter);
void _mod(stack_t **head, unsigned int counter);
void _pchar(stack_t **head, unsigned int counter);
void _pstr(stack_t **head, unsigned int counter);
void _stack(stack_t **head, unsigned int counter);
void _queue(stack_t **head, unsigned int counter);
void _addqueue(stack_t **head, int n);

#endif
