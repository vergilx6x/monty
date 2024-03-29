#include "monty.h"
/**
 * _pstr - Prints the string starting from the top
 * followed by a new
 * @head: Stack head
 * @counter: Line counter
 * Return: No return
*/
void _pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
