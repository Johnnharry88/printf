#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct format - conversion sprcifier matcher for printf
 * @spec: speicifer character pointer.
 * @action: pinter to function that perfomrs conversion on spec.
 */
typedef struct format
{
	char *spec;
	int (*action)();
}check;

int _printf(const char *format, ...);
int _putchar(char c);
int string_printer(va_list tools);
int chara_printer(va_list tools);
/**int printer_37(va_list tools);
int integer_printer(va_list tools);
int decimal_printer(va_list tools);
int str_rev_printer(va_list tools);
int bin_printer(va_list tools);
int unsigned_printer(va_list tools);
int octal_printer(va_list tools);
int rot13_printer(va_list tools);
int hex_printer(va_list tools);
int HEX_printer(va_list tools);
int pointer_printer(va_list tools);
int _printf(const char *format, ...);
int exclusive_string_printer(va_list tools);**/
#endif
