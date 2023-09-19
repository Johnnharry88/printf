#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flag & 1)
#define SPACE_FLAG ((flag >> 1) & 1)
#define HASH_FLAG ((flag >> 2) & 1)
#define ZERO_FLAG ((flag >> 3) & 1)
#define NEGATIVE_FLAG ((flag >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct shield_s
{
	char *buffer;
	char *start;
	unsigned int len;
} shield_t;

/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, shield_t *,
			unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

int _printf(const char *format, ...);

/* Conversion Specifier Functions */
unsigned int convert_c(va_list args, shield_t *result,
		unsigned char flag, int width, int precisions, unsigned char len);
unsigned int convert_s(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_di(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_percent(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_b(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_u(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_o(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_x(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_X(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_S(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_p(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_r(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);
unsigned int convert_R(va_list args, shield_t *result,
		unsigned char flag, int width, int precision, unsigned char len);

/* Handlers */
unsigned char handle_flags(const char *flags, char *index);
unsigned char handle_length(const char *modifier, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, shield_t *,
		unsigned char, int, int, unsigned char);

/* Modifiers */
unsigned int print_width(shield_t *result, unsigned int printed,
		unsigned char flag, int width);
unsigned int print_string_width(shield_t *result,
		unsigned char flag, int width, int precision, int size);
unsigned int print_neg_width(shield_t *result, unsigned int printed,
		unsigned char flag, int width);

/* Helper Functions */
shield_t *init_buffer(void);
void free_buffer(shield_t *result);
unsigned int _memcpy(shield_t *output, const char *src, unsigned int n);
unsigned int convert_sbase(shield_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int convert_ubase(shield_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

#endif /* HOLBERTON_H */
