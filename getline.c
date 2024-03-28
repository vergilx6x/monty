#include "monty.h"

#define INITIAL_BUFFER_SIZE 128

/**
 * my_getline - Reads a line from stdin
 * @lineptr: pointer to buffer
 * @n: Not used
 * @stream: Pointer to stream
 * Return: Number of bytes
*/

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;
	char *temp;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = INITIAL_BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if ((pos + 1) >= *n)
		{
			*n *= 2;
			temp = (char *)realloc(*lineptr, *n);
			if (temp == NULL)
				return (-1);
			*lineptr = temp;
		}
		(*lineptr)[pos++] = (char)c;
		if (c == '\n')
			break;
	}
	if (pos == 0)
		return (-1);
	(*lineptr)[pos] = '\0';
	return (pos);
}
