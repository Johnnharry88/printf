#include "main.h"
/**
 * _printf - functions that chooses the correct function according
 * the fomrat specifer
 * @format: format
 * Return: Integer value of length of strings
 */
int _printf(const char *format, ...)
{
	check list[] = {
		{"%s", string_printer},
		{"%c", chara_printer},
		{"%%", printer_37},
		{"%i", integer_printer},
		{"%d", decimal_printer},
		{"%r", str_rev_printer},
		{"%b", bin_printer},
		{"%u", unsigned_printer},
		{"%o", octal_printer},
		{"%R", rot13_printer},
		{"%x", hex_printer},
		{"%X", HEX_printer},
		{"%$", exclusive_string_printer},
		{"%p", pointer_printer},
		};
		
	va_list tools;
	int count = 0; 
	int rec; 
	int strcount = 0;

	va_start(tools, format);

	if (format == NULL)
		return (-1);
	if (format[count] == '%' && format[count + 1] == '\0')
		return (-1);
Ref:
	while (format[count] != '\0')
	{
		for (rec = 13; rec >= 0; rec--)
		{
			if (list[rec].spec[0] == format[count] && list[rec].spec[1] == format[count + 1])
			{
				strcount = strcount + list[rec].action(tools);
				count = count + 2;
				goto Ref;
			}
		}
		_putchar(format[count]);
		strcount += 1;
		count = count + 1;
	}
	va_end(tools);
	return (strcount);
}
