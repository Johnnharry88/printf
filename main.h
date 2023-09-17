#ifndef MAIN_H
#define MAIN_H

<<<<<<< HEAD
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

#define SHORT 1
#define LONG 2

typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
} converter_t;

typedef struct flags_s
{
	unsigned char flags;
	unsigned char value;
} flag_t;

int _printf(const char *format, ....);

unsigned int convert_c(va_list args, buffer_t *output, 
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_s(va_list args, buffer_t *output, 
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_di(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_b(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_u(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_o(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_x(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec unsigned char len);
unsigned int convert_X(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_S(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_r(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_R(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);

unsigned char handle_flags(const char *flags, char *index);
unsigned char handle_length(const char *modifier, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *, unsigned char, int, int, unsigned char);

unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);

buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);
=======
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
>>>>>>> b23b344d7699863e612c19ee90201e83795b3ce4
#endif
