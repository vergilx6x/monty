#include "monty.h"
/**
 * _swap - Swaps the top two elements
 * @head: Stack head
 * @counter: Line number
 * Return: No return
*/
void _swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(args.file);
		free(args.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
