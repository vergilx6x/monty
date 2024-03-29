#include "monty.h"
/**
 * _stack - Prints the top
 * @head: Stack head
 * @counter: Line counter
 * Return: <no return
*/
void _stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	args.queue_flag = 0;
}

/**
 * _queue - Prints the top
 * @head: Stack head
 * @counter: line_number
 * Return: no return
*/
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	args.queue_flag = 1;
}

/**
 * _addqueue - Adds node at the tail stack
 * @n: Value to insert
 * @head: Head of the stack
 * Return: No return
*/
void _addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
