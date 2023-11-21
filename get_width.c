#include "main.h"

/**
 * geting_width - Calculate the width for printing
 * @format: Formatted string in which to print the arguments.
 * @n: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int geting_width(const char *format, int *n, va_list list)
{
	int cur_n;
	int wid = 0;

	for (cur_n = *n + 1; format[cur_n] != '\0'; cur_n++)
	{
		if (ifis_digit(format[cur_n]))
		{
			wid *= 10;
			wid += format[cur_n] - '0';
		}
		else if (format[cur_n] == '*')
		{
			cur_n++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*n = cur_n - 1;

	return (wid);
}
