#include "main.h"

unsigned int convert_c(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_percent(va_list args, shield_t *output,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_p(va_list args, shield_t *output,
		unsigned char flag, int width, int precision, unsigned char len);

/**
 * convert_c - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_c(va_list args, shield_t *output,
		unsigned char flag, int width, int precision, unsigned char len)
{
	char c;
	unsigned int ret = 0;

	(void)precision;
	(void)len;

	c = va_arg(args, int);

	ret += print_width(output, ret, flag, width);
	ret += _memcpy(output, &c, 1);
	ret += print_neg_width(output, ret, flag, width);

	return (ret);
}

/**
 * convert_percent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
unsigned int convert_percent(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	char percent = '%';
	unsigned int ret = 0;

	(void)args;
	(void)precision;
	(void)len;

	ret += print_width(result, ret, flag, width);
	ret += _memcpy(result, &percent, 1);
	ret += print_neg_width(result, ret, flag, width);

	return (ret);
}

/**
 * convert_p - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_p(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int ret = 0;

	(void)len;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(result, null, 5));

	flag |= 32;
	ret += convert_ubase(result, address, "0123456789abcdef",
			flag, width, precision);
	ret += print_neg_width(result, ret, flag, width);

	return (ret);
}
