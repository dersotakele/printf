#include "main.h"

/**
 * geting_precision -a function Calculate the precision for printing
 * @format: Formatted string in which to print the arguments
 * @n: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int geting_precision(const char *format, int *n, va_list list)
{
	int cur_n = *n + 1;
	int pre_ion = -1;

	if (format[cur_n] != '.')
		return (pre_ion);

	pre_ion = 0;

	for (cur_n += 1; format[cur_n] != '\0'; cur_n++)
	{
		if (ifis_digit(format[cur_n]))
		{
			pre_ion *= 10;
			pre_ion += format[cur_n] - '0';
		}
		else if (format[cur_n] == '*')
		{
			cur_n++;
			pre_ion = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*n = cur_n - 1;

	return (pre_ion);
}
