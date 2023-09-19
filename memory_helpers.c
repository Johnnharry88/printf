/*
 * File: memory_helpers.c
 * Auth: Brennan D Baraban
 */

#include "holberton.h"

unsigned int _memcpy(shield_t *output, const char *src, unsigned int n);
void free_buffer(shield_t *output);
shield_t *init_buffer(void);

/**
 * _memcpy - Copies n bytes from memory area src to
 *           the buffer contained in a buffer_t struct.
 * @output: A buffer_t struct.
 * @src: A pointer to the memory area to copy.
 * @n: The number of bytes to be copied.
 *
 * Return: The number of bytes copied.
 */
unsigned int _memcpy(shield_t *output, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(output->buffer) = *(src + index);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}

		else
			(output->buffer)++;
	}

	return (n);
}

/**
 * free_buffer - Frees a buffer_t struct.
 * @output: The buffer_t struct to be freed.
 */
void free_buffer(shield_t *output)
{
	free(output->start);
	free(output);
}

/**
 * init_buffer - Initializes a variable of struct type buffer_t.
 *
 * Return: A pointer to the initialized buffer_t.
 */
shield_t *init_buffer(void)
{
	shield_t *output;

	output = malloc(sizeof(shield_t));
	if (output == NULL)
		return (NULL);

	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}

	output->start = output->buffer;
	output->len = 0;

	return (output);
}
