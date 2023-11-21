#include "main.h"

/**
 * handling_write_char - Prints a string
 * @s: char types.
 * @buff: Buffer array to handle print
 * @flag:  Calculate active flags.
 * @wid: get width.
 * @pre_ion: precision specifier
 * @siz: Size specifier
 *
 * Return: Number of chars printed.
 */
int handling_write_char(char s, char buff[],
	int flag, int wid, int pre_ion, int siz)
{ /* char is stored at left and paddind at buffer's right */
	int j = 0;
	char paddd = ' ';

	UNUSED(pre_ion);
	UNUSED(siz);

	if (flag & F_ZERO)
		paddd = '0';

	buff[j++] = s;
	buff[j] = '\0';

	if (wid > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < wid - 1; j++)
			buff[BUFF_SIZE - j - 2] = paddd;

		if (flag & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - j - 1], wid - 1));
		else
			return (write(1, &buff[BUFF_SIZE - j - 1], wid - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/**
 * write_number - Prints a string
 * @ifis_negative: Lista of arguments
 * @ind: char types.
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width.
 * @pre_ion: precision specifier
 * @siz: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int ifis_negative, int ind, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	int leng = BUFF_SIZE - ind - 1;
	char paddd = ' ', extra_ch = 0;

	UNUSED(siz);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		paddd = '0';
	if (ifis_negative)
		extra_ch = '-';
	else if (flag & F_PLUS)
		extra_ch = '+';
	else if (flag & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buff, flag, wid, pre_ion,
		leng, paddd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buff: Buffer
 * @flag: Flags
 * @wid: width
 * @pre_ion: Precision specifier
 * @leng: Number length
 * @paddd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buff[],
	int flag, int wid, int pre_ion,
	int leng, char paddd, char extra_c)
{
	int j, paddd_start = 1;

	if (pre_ion == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && wid == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (pre_ion == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		buff[ind] = paddd = ' '; /* width is displayed with padding ' ' */
	if (pre_ion > 0 && pre_ion < leng)
		paddd = ' ';
	while (pre_ion > leng)
		buff[--ind] = '0', leng++;
	if (extra_c != 0)
		leng++;
	if (wid > leng)
	{
		for (j = 1; j < wid - leng + 1; j++)
			buff[j] = paddd;
		buff[j] = '\0';
		if (flag & F_MINUS && paddd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], leng) + write(1, &buff[1], j - 1));
		}
		else if (!(flag & F_MINUS) && paddd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[1], j - 1) + write(1, &buff[ind], leng));
		}
		else if (!(flag & F_MINUS) && paddd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buff[--paddd_start] = extra_c;
			return (write(1, &buff[paddd_start], j - paddd_start) +
				write(1, &buff[ind], leng - (1 - paddd_start)));
		}
	}
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], leng));
}

/**
 * writing_unsgnd - Writes an unsigned number
 * @ifis_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flag: Flags specifiers
 * @wid: Width specifier
 * @pre_ion: Precision specifier
 * @siz: Size specifier
 *
 * Return: Number of written chars.
 */
int writing_unsgnd(int ifis_negative, int ind,
	char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	/* The number is stored at the bufer's right and starts at position i */
	int leng = BUFF_SIZE - ind - 1, j = 0;
	char paddd = ' ';

	UNUSED(ifis_negative);
	UNUSED(siz);

	if (pre_ion == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (pre_ion > 0 && pre_ion < leng)
		paddd = ' ';

	while (pre_ion > leng)
	{
		buff[--ind] = '0';
		leng++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		paddd = '0';

	if (wid > leng)
	{
		for (j = 0; j < wid - leng; j++)
			buff[j] = paddd;

		buff[j] = '\0';

		if (flag & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buff[ind], leng) + write(1, &buff[0], j));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buff[0], j) + write(1, &buff[ind], leng));
		}
	}

	return (write(1, &buff[ind], leng));
}

/**
 * writing_pointer - Write a memory address
 * @buff: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @leng: Length of number
 * @wid: Wwidth specifier
 * @flag: Flags specifier
 * @paddd: Char representing the padding
 * @extra_c: Char representing extra char
 * @paddd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int writing_pointer(char buff[], int ind, int leng,
	int wid, int flag, char paddd, char extra_c, int paddd_start)
{
	int j;

	if (wid > leng)
	{
		for (j = 3; j < wid - leng + 3; j++)
			buff[j] = paddd;
		buff[j] = '\0';
		if (flag & F_MINUS && paddd == ' ')/* Asign extra char to left of buffer */
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], leng) + write(1, &buff[3], j - 3));
		}
		else if (!(flag & F_MINUS) && paddd == ' ')/* extra char to left of buffer */
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[3], j - 3) + write(1, &buff[ind], leng));		}
		else if (!(flag & F_MINUS) && paddd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buff[--paddd_start] = extra_c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[paddd_start], j - paddd_start) +
				write(1, &buff[ind], leng - (1 - paddd_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], BUFF_SIZE - ind - 1));
}
