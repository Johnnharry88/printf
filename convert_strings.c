#include "main.h"

unsigned int convert_s(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_S(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_r(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_R(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);

/**
 * convert_s - Converts an argument to a string and
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
unsigned int convert_s(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	char *str, *null = "(null)";
	int size;
	unsigned int ret = 0;

	(void)flag;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(result, null, 6));

	for (size = 0; *(str + size);)
		size++;

	ret += print_string_width(result, flag, width, precision, size);

	precision = (precision == -1) ? size : precision;
	while (*str != '\0' && precision > 0)
	{
		ret += _memcpy(result, str, 1);
		precision--;
		str++;
	}

	ret += print_neg_width(result, ret, flag, width);

	return (ret);
}

/**
 * convert_S - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
unsigned int convert_S(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int size, index;
	unsigned int ret = 0;

	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(result, null, 6));

	for (size = 0; str[size];)
		size++;

	ret += print_string_width(result, flag, width, precision, size);

	precision = (precision == -1) ? size : precision;
	for (index = 0; *(str + index) != '\0' && index < precision; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			ret += _memcpy(result, hex, 2);
			if (*(str + index) < 16)
				ret += _memcpy(result, &zero, 1);
			ret += convert_ubase(result, *(str + index),
					     "0123456789ABCDEF", flag, 0, 0);
			continue;
		}
		ret += _memcpy(result, (str + index), 1);
	}

	ret += print_neg_width(result, ret, flag, width);

	return (ret);
}

/**
 * convert_r - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be reversed.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_r(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	char *str, *null = "(null)";
	int sizes, end, i;
	unsigned int ret = 0;

	(void)flag;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(result, null, 6));

	for (sizes = 0; *(str + sizes);)
		sizes++;

	ret += print_string_width(result, flag, width, precision, sizes);

	end = sizes - 1;
	precision = (precision == -1) ? sizes : precision;
	for (i = 0; end >= 0 && i < precision; i++)
	{
		ret += _memcpy(result, (str + end), 1);
		end--;
	}

	ret += print_neg_width(result, ret, flag, width);

	return (ret);
}

/**
 * convert_R - Converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A lenth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_R(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int i, j, size;
	unsigned int ret = 0;

	(void)flag;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(result, null, 6));

	for (size = 0; *(str + size);)
		size++;

	ret += print_string_width(result, flag, width, precision, size);

	precision = (precision == -1) ? size : precision;
	for (i = 0; *(str + i) != '\0' && i < precision; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				ret += _memcpy(result, (rot13 + j), 1);
				break;
			}
		}
		if (j == 52)
			ret += _memcpy(result, (str + i), 1);
	}

	ret += print_neg_width(result, ret, flag, width);

	return (ret);
}
