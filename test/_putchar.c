#include <unistd.h>
/**
 * _putchar - function that prints to screen
 * @c:: character to be printed.
 * Return: (1)
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
