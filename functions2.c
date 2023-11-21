#include "main.h"

/**
 * printing_apointer -the Prints the value of a pointer variable
 * @type: List a number of arguments in the function
 * @buff: Buffer array to handle print
 * @flag: it the  Calculate active flags
 * @wid: get width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Numb of charscter printed.
 */
int printing_pointer(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	char extra_char = 0, paddd = ' ';
	int ind = BUFF_SIZE - 2, leng = 2, paddd_start = 1;
	unsigned long number_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(wid);
	UNUSED(siz);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(pre_ion);

	number_addrs = (unsigned long)addrs;

	while (number_addrs > 0)
	{
		buff[ind--] = map_to[number_addrs % 16];
		number_addrs /= 16;
		leng++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		paddd = '0';
	if (flag & F_PLUS)
		extra_char = '+', leng++;
	else if (flag & F_SPACE)
		extra_char = ' ', leng++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (writing_pointer(buff, ind, leng,
		wid, flag, paddd, extra_char, paddd_start));
}

/**
 * printing_non_printable - Prints ascii codes in hexa of non printable chars
 * @type: List a number of arguments in the function
 * @buff: Buffer array to handle print
 * @flag: it the  Calculate active flags
 * @wid: get width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Number of chars printed
 */
int printing_non_printable(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	int n = 0, offset = 0;
	char *str = va_arg(type, char *);

	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre_ion);
	UNUSED(siz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[n] != '\0')
	{
		if (ifis_printable(str[n]))
			buff[n + offset] = str[n];
		else
			offset += appending_hexa_code(str[n], buff, n + offset);

		n++;
	}

	buff[n + offset] = '\0';

	return (write(1, buff, n + offset));
}

/**
 * printing_reverse - Prints reverse string.
 * @type: List a number of arguments in the function
 * @buff: Buffer array to handle print
 * @flag: it the  Calculate active flags
 * @wid: get width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Number of chars printed
 */

int printing_reverse(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	char *str;
	int n, counter = 0;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(siz);

	str = va_arg(type, char *);

	if (str == NULL)
	{
		UNUSED(pre_ion);

		str = ")Null(";
	}
	for (n = 0; str[n]; n++)
		;

	for (n = n - 1; n >= 0; n--)
	{
		char m = str[n];

		write(1, &m, 1);
		counter++;
	}
	return (counter);
}
/**
 * printing_rot13string - Print a string in rot13.
 * @type: List a number of arguments in the function
 * @buff: Buffer array to handle print
 * @flag: it the  Calculate active flags
 * @wid: get width
 * @pre_ion: Precision specification
 * @siz: Size specifier
 * Return: Number of chars printed
 */
int printing_rot13string(va_list type, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	char y;
	char *str;
	unsigned int i, j;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(type, char *);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre_ion);
	UNUSED(siz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				y = out[j];
				write(1, &y, 1);
				counter++;
				break;
			}
		}
		if (!in[j])
		{
			y = str[i];
			write(1, &y, 1);
			counter++;
		}
	}
	return (counter);
}
