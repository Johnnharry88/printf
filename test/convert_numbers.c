#include "main.h"

unsigned int convert_di(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_b(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_u(va_list args, shield_t *result,
		unsigned char flags, int width, int precision, unsigned char len);
unsigned int convert_o(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);

/**
 * convert_di - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_di(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	long int d, copy;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (len == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (len == SHORT)
		d = (short)d;

	/* Handle space flag */
	if (SPACE_FLAG == 1 && d >= 0)
		ret += _memcpy(result, &space, 1);

	if (precision <= 0 && NEGATIVE_FLAG == 0) /* Handle width  */
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;

		/* Handle plus flag when zero flag is active */
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			ret += _memcpy(result, &plus, 1);
		/*Print negative sign when zero flag is active */
		if (ZERO_FLAG == 1 && d < 0)
			ret += _memcpy(result, &neg, 1);

		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (width -= count; width > 0; width--)
			ret += _memcpy(result, &pad, 1);
	}

	/* Print negative sign when zero flag is not active */
	if (ZERO_FLAG == 0 && d < 0)
		ret += _memcpy(result, &neg, 1);
	/* Handle plus flag when zero flag is not active */
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		ret += _memcpy(result, &plus, 1);

	if (!(d == 0 && precision == 0))
		ret += convert_sbase(result, d, "0123456789",
				flag, 0, precision);

	ret += print_neg_width(result, ret, flag, width);

	return (ret);
}

/**
 * convert_b - Converts an unsigned int argument to binary
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
unsigned int convert_b(va_list args, shield_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)len;

	return (convert_ubase(output, num, "01", flags, wid, prec));
}

/**
 * convert_o - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list poinitng to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_o(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(result, &zero, 1);

	if (!(num == 0 && precision == 0))
		ret += convert_ubase(result, num, "01234567",
				flag, width, precision);

	ret += print_neg_width(result, ret, flag, width);

	return (ret);
}

/**
 * convert_u - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_u(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	unsigned long int number;
	unsigned int rets = 0;

	if (len == LONG)
		number = va_arg(args, unsigned long int);
	else
		number = va_arg(args, unsigned int);
	if (len == SHORT)
		number = (unsigned short)number;

	if (!(number == 0 && precision == 0))
		rets += convert_ubase(result, number, "0123456789",
				flag, width, precision);

	rets += print_neg_width(result, rets, flag, width);

	return (rets);
}
