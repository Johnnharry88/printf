#include "main.h"
/**
 * string_printer - function that prints string to the standard output
 * @tools: arguments to be printed
 * Return: 1
 */
int string_printer(va_list tools)
{
	char alx;

	alx = va_arg(tools, int);
	_putchar(alx);
	return (1);
}
