#include "main.h"

unsigned int convert_x(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_X(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);

/**
 * convert_x - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_x(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	unsigned long int number;
	unsigned int rets = 0;
	char *lead = "0x";

	if (len == LONG)
		number = va_arg(args, unsigned long int);
	else
		number = va_arg(args, unsigned int);
	if (len == SHORT)
		number = (unsigned short)number;

	if (HASH_FLAG == 1 && number != 0)
		rets += _memcpy(result, lead, 2);

	if (!(number == 0 && precision == 0))
		rets += convert_ubase(result, number, "0123456789abcdef",
				flag, width, precision);

	rets += print_neg_width(result, rets, flag, width);

	return (rets);
}

/**
 * convert_X - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_X(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	unsigned long int number;
	unsigned int rets = 0;
	char *lead = "0X";

	if (len == LONG)
		number = va_arg(args, unsigned long);
	else
		number = va_arg(args, unsigned int);
	if (len == SHORT)
		number = (unsigned short)number;

	if (HASH_FLAG == 1 && number != 0)
		rets += _memcpy(result, lead, 2);

	if (!(number == 0 && precision == 0))
		rets += convert_ubase(result, number, "0123456789ABCDEF",
				flag, width, precision);

	rets += print_neg_width(result, rets, flag, width);

	return (rets);
}
