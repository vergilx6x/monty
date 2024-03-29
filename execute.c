#include "monty.h"

/**
* execute - Execute the opcode
* @stack: Head of the linked list - stack
* @counter: Linecounter
* @file: Poiner to monty file
* @buffer: Line content
* Return: no return
*/

int execute(char *buffer, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t ops[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul},
		{"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(buffer, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	args.args = strtok(NULL, " \n\t");
	while (ops[i].opcode && opcode)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (opcode && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(file);
		free(buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
* free_stack - Frees a doubly linked list
* @head: Head of the list
*/

void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
