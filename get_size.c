#include "main.h"

/**
 * geting_size -a function that Calculate the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @n: List of arguments to be printed.
 *
 * Return: Precision.
 */
int geting_size(const char *format, int *n)
{
	int cur_n = *n + 1;
	int siz = 0;

	if (format[cur_n] == 'l')
		siz = S_LONG;
	else if (format[cur_n] == 'h')
		siz = S_SHORT;

	if (siz == 0)
		*n = cur_n - 1;
	else
		*n = cur_n;

	return (siz);
}
