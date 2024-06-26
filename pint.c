#include "monty.h"
/**
 * _pint - Prints the top
 * @head: Stack head
 * @counter: Line counter
 * Return: No return
*/
void _pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(args.file);
		free(args.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
