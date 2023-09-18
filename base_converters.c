/*
 * File: base_converters.c
 * Auth: Brennan D Baraban
 */

#include "holberton.h"

unsigned int change_s(shield_t *result, long int number, char *bases,
		unsigned char flag, int width, int precision);
unsigned int change_u(shield_t *result,
		unsigned long int number, char *bases,
		unsigned char flag, int width, int precision);

/**
 * convert_sbase - Converts a signed long to an inputted base and stores
 *                 the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: A signed long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int change_s(shield_t *result, long int number, char *bases,
		unsigned char flag, int width, int precision)
{
	int sizes;
	char digits, pads = '0';
	unsigned int ret = 1;

	for (sizes = 0; *(bases + sizes);)
		sizes++;

	if (number >= sizes || number <= -sizes)
		ret += change_s(result, number / sizes, bases,
				flag, width - 1, precision - 1);

	else
	{
		for (; precision > 1; precision--, width--) /* Handle precision */
			ret += _memcpy(result, &pads, 1);

		if (NEGATIVE_FLAG == 0) /* Handle width */
		{
			pads = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; width > 1; width--)
				ret += _memcpy(result, &pads, 1);
		}
	}

	digits = bases[(number < 0 ? -1 : 1) * (number % sizes)];
	_memcpy(result, &digits, 1);

	return (ret);
}

/**
 * convert_ubase - Converts an unsigned long to an inputted base and
 *                 stores the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: An unsigned long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int change_u(shield_t *result, unsigned long int number, char *bases,
		unsigned char flag, int width, int precision)
{
	unsigned int sizes, rets = 1;
	char digits, pads = '0', *leads = "0x";

	for (sizes = 0; *(bases + sizes);)
		sizes++;

	if (number >= sizes)
		rets += change_u(result, number / sizes, bases,
				flag, width - 1, precision - 1);

	else
	{
		if (((flag >> 5) & 1) == 1) /* Printing a ptr address */
		{
			width -= 2;
			precision -= 2;
		}
		for (; precision > 1; precision--, width--) /* Handle precision */
			rets += _memcpy(result, &pads, 1);

		if (NEGATIVE_FLAG == 0) /* Handle width */
		{
			pads = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; width > 1; width--)
				rets += _memcpy(result, &pads, 1);
		}
		if (((flag >> 5) & 1) == 1) /* Print 0x for ptr address */
			rets += _memcpy(result, leads, 2);
	}

	digits = bases[(number % sizes)];
	_memcpy(result, &digits, 1);

	return (rets);
}
