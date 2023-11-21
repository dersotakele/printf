#include "main.h"

/**
 * print_unsignednum - that  Prints an unsigned number
 * @type: List a number of arguments in the function
 * @buff: Buffer array to handle print
 * @flag: it the  Calculate active flags
 * @wid: get width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed.
 */
int print_unsignednum(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	int n = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);

	number = converting_size_unsgnd(number, siz);

	if (number == 0)
		buff[n--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[n--] = (number % 10) + '0';
		number /= 10;
	}

	n++;

	return (writing_unsgnd(0, n, buff, flag, wid, pre_ion, siz));
}
/**
 * printing_octal -  a function Prints an unsigned number in octal notation
 * @type: List a number of arguments in the function
 * @buff: Buffer array to handle print
 * @flag: it the  Calculate active flags
 * @wid: get width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed.
 */
int printing_octal(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{

	int n = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(wid);

	number = converting_size_unsgnd(number, siz);

	if (number == 0)
		buff[n--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[n--] = (number % 8) + '0';
		number /= 8;
	}

	if (flag & F_HASH && init_number != 0)
		buff[n--] = '0';

	n++;

	return (writing_unsgnd(0, n, buff, flag, wid, pre_ion, siz));
}

/**
 * printing_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @type: List a number of arguments in the function
 * @buff: Buffer array to handle print
 * @flag: it the  Calculate active flags
 * @wid: get width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed.
 */
int printing_hexadecimal(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	return (printing_hexa(type, "0123456789abcdef", buff,
		flag, 'x', wid, pre_ion, siz));
}

/**
 * printing_hexa_upper - Prints an unsigned num  upper hexadecimal
 * @type: List a number of arguments in the function
 * @buff: Buffer array to handle print
 * @flag: it the  Calculate active flags
 * @wid: get width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed.
 */
int printing_hexa_upper(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	return (printing_hexa(type, "0123456789ABCDEF", buff,
		flag, 'X', wid, pre_ion, siz));
}

/**
 * printing_hexa - a function Prints a hexadecimal number in lower or upper
 * @type: List a number of arguments in the function
 * @buff: Buffer array to handle print
 * @flag: it the  Calculate active flags
 * @map_to: Array of values to map the number to
 * @flag_character: it Calculates active flags
 * @wid: get width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed.
 */
int printing_hexa(va_list type, char map_to[], char buff[],
	int flag, char flag_character, int wid, int pre_ion, int siz)
{
	int n = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(wid);

	number = converting_size_unsgnd(number, siz);

	if (number == 0)
		buff[n--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[n--] = map_to[number % 16];
		number /= 16;
	}

	if (flag & F_HASH && init_number != 0)
	{
		buff[n--] = flag_character;
		buff[n--] = '0';
	}

	n++;

	return (writing_unsgnd(0, n, buff, flag, wid, pre_ion, siz));
}
