#include "main.h"

/**
<<<<<<< HEAD
 * print_character -it Prints a character
 * @type: List of arguments using vardic Function
 * @buff: the Buffer array to handle print Function
 * @flag:  Calculate active flag in the code
 * @wid: Width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed
=======
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculate active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
>>>>>>> 333de7cde74bce8e6c68fac0ded8f017297c78e9
 */
int print_character(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	char s = va_arg(type, int);

	return (handling_write_char(s, buff, flag, wid, pre_ion, siz));
}
/**
 * print_str -a function that  Prints a string
 *@type: List of arguments using vardic Function
 * @buff: the Buffer array to handle print Function
 * @flag:  Calculate active flag in the code
 * @wid: Width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed
 */
int print_str(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	int leng = 0, n;
	char *str = va_arg(type, char *);

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre_ion);
	UNUSED(siz);
	if (str == NULL)
	{
		str = "(null)";
		if (pre_ion >= 6)
			str = "      ";
	}

	while (str[leng] != '\0')
		leng++;

	if (pre_ion >= 0 && pre_ion < leng)
		leng = pre_ion;

	if (wid > leng)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], leng);
			for (n = wid - leng; n > 0; n--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (n = wid - leng; n > 0; n--)
				write(1, " ", 1);
			write(1, &str[0], leng);
			return (wid);
		}
	}

	return (write(1, str, leng));
}
/**
 * print_per - Prints a percent(%) sign
 * @type: List of arguments using vardic Function
 * @buff: the Buffer array to handle print Function
 * @flag:  Calculate active flag in the code
 * @wid: Width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed
 */
int print_per(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	UNUSED(type);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre_ion);
	UNUSED(siz);
	return (write(1, "%%", 1));
}

/*
 * print_intger - afunction that Prints an  integer
 *@type: List of arguments using vardic Function
 * @buff: the Buffer array to handle print Function
 * @flag:  Calculate active flag in the code
 * @wid: Width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed
 */
int print_intger(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	int n = BUFF_SIZE - 2;
	int ifis_negative = 0;
	long int m = va_arg(type, long int);
	unsigned long int number;

	m = converting_size_number(m, siz);

	if (m == 0)
		buff[n--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)m;

	if (m < 0)
	{
		number = (unsigned long int)((-1) * m);
		ifis_negative = 1;
	}

	while (number > 0)
	{
		buff[m--] = (number % 10) + '0';
		number /= 10;
	}

	n++;

	return (write_number(ifis_negative, n, buff, flag, wid, pre_ion, siz));
}

/**
 * print_abinary - a function that Prints an unsigned number
 *@type: List of arguments using vardic Function
 * @buff: the Buffer array to handle print Function
 * @flag:  Calculate active flag in the code
 * @wid: Width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Num of characters printed
 */
int print_abinary(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	unsigned int x, y, j, sum;
	unsigned int d[32];
	int counter;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre_ion);
	UNUSED(siz);

	x = va_arg(type, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	d[0] = x / y;
	for (j = 1; j < 32; j++)
	{
		y /= 2;
		d[j] = (x / y) % 2;
	}
	for (j = 0, sum = 0, counter = 0; j < 32; j++)
	{
		sum += d[j];
		if (sum || j == 31)
		{
			char p = '0' + d[j];

			write(1, &p, 1);
			counter++;
		}
	}
	return (counter);
}
