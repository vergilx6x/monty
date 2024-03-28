#include "monty.h"

args_s args = {NULL, NULL, NULL, 0};

/**
* main - Monty code interpreter
* @argc: Number of arguments
* @argv: Strings of arguments
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *buffer;
	FILE *file;
	size_t bytes = 0;
	ssize_t line_read = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	args.file = file;
	while (line_read > 0)
	{
		buffer = NULL;
		line_read = getline(&buffer, &bytes, file);
		args.buffer = buffer;
		counter++;
		if (line_read > 0)
		{
			execute(buffer, &stack, counter, file);
		}
		free(buffer);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
