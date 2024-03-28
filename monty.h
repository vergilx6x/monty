#ifndef MONTY_H
#define MONTY_H
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
 * struct args_s - variables -args, file, line content
 * @args: value
 * @file: pointer to monty file
 * @buffer: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct args_s
{
	char *args;
	FILE *file;
	char *buffer;
	int lifi;
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

#endif
