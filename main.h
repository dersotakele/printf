#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAG */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZE */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handling_print(const char *fmt, int *n,
va_list list, char buff[], int flag, int wid, int pre_ion, int siz);

/* Funtions to print chars and strings */
int print_character(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);
int print_str(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);
int print_per(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);

/* Functions to print numbers */
int print_intger(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);
int print_abinary(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);
int print_unsignednum(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);
int printing_octal(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);
int printing_hexadecimal(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);
int printing_hexa_upper(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);

int printing_hexa(va_list type, char map_to[],
char buff[], int flag, char flag_character, int wid, int pre_ion, int siz);

/* Function to print non printable characters */
int printing_non_printable(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);

/* Funcion to print memory address */
int printing_pointer(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);

/* Funciotns to handle other specifiers */
int geting_flags(const char *format, int *n);
int geting_width(const char *format, int *n, va_list list);
int geting_precision(const char *format, int *n, va_list list);
int geting_size(const char *format, int *n);

/*Function to print string in reverse*/
int printing_reverse(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);

/*Function to print a string in rot 13*/
int printing_rot13string(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz);

/* width handler */
int handling_write_char(char s, char buff[],
	int flag, int wid, int pre_ion, int siz);
int write_number(int ifis_positive, int ind, char buff[],
	int flag, int wid, int prec_ion, int siz);
int write_num(int ind, char buff[], int flag, int wid, int pre_ion,
	int leng, char paddd, char extra_c);
int writing_pointer(char buff[], int ind, int leng,
	int wid, int flag, char paddd, char extra_c, int paddd_start);

int writing_unsgnd(int ifis_negative, int ind,
char buff[],
	int flag, int wid, int pre_ion, int siz);

/****************** UTILS ******************/
int ifis_printable(char);
int appending_hexa_code(char, char[], int);
int ifis_digit(char);

long int converting_size_number(long int number, int siz);
long int converting_size_unsgnd(unsigned long int number, int siz);

#endif /* MAIN_H */
