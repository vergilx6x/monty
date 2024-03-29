#include "monty.h"
/**
  *_sub- Substract the top two elements
  *@head: Stack head
  *@counter: line counter
  *Return: No return
 */
void _sub(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int result, len = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(args.file);
		free(args.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
