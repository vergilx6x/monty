#include "monty.h"

/**
 * _pall - Prints the stack
 * @head: Stack head
 * @counter: Not used
 * Return: No return
*/

void _pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _push - Adds a node to the stack
 * @head: Stack head
 * @counter: Line counter
 * Return: no return
*/

void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (args.args)
	{
		if (args.args[0] == '-')
			j++;
		for (; args.args[j] != '\0'; j++)
		{
			if (args.args[j] > 57 || args.args[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(args.file);
			free(args.buffer);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(args.file);
		free(args.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(args.args);
	_addnode(head, n);
}

/**
 * _addnode - Adds a node to the stack
 * @head: Head of the stack
 * @n: Value to enter
 * Return: No return
*/

void _addnode(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
