#include "main.h"

/**
 * ifis_printable - Evaluate if a char is printable
 * @s: Char to be evaluated.
 *
 * Return: 1 if s is printable, 0 otherwise
 */
int ifis_printable(char s)
{
	if (s >= 32 && s < 127)
		return (1);

	return (0);
}

/**
 * appending_hexa_code - Append ascci in hexadecimal code to buffer
 * @buff: Array of chars.
 * @j: Index at which to start appending.
 * @asci_code: ASSCI CODE.
 *
 * Return: Always 3
 */
int appending_hexa_code(char asci_code, char buff[], int j)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (asci_code < 0)
		asci_code *= -1;

	buff[j++] = '\\';
	buff[j++] = 'x';

	buff[j++] = map_to[asci_code / 16];
	buff[j] = map_to[asci_code % 16];

	return (3);
}

/**
 * ifis_digit - Verifies if a char is a digit
 * @s: Char to be evaluated
 *
 * Return: 1 if s is a digit, 0 otherwise
 */
int ifis_digit(char s)
{
	if (s >= '0' && s <= '9')
		return (1);

	return (0);
}

/**
 * converting_size_number - Casts a number to the specified size
 * @number: Number to be casted.
 * @siz: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int converting_size_number(long int number, int siz)
{
	if (siz == S_LONG)
		return (number);
	else if (siz == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * converting_size_unsgnd - Casts a number to the specified size
 * @number: Number to be casted
 * @siz: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int converting_size_unsgnd(unsigned long int number, int siz)
{
	if (siz == S_LONG)
		return (number);
	else if (siz == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
