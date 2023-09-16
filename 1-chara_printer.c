#include "main.h"
/**
 * chara_printer - function that prints character to screen
 * @tools: Argument list
 * Return: 1
 */
int chara_printer(va_list tools)
{
	char alx;

	alx = va_arg(tools, int);
	_putchar(alx);
	return (1);
}
