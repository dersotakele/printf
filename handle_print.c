#include "main.h"
/**
 * handling_print - afunction Prints an argument basedits type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buff: Buffer array to handle print.
 * @flag: Calculate active flags
 * @wid: get width.
 * @pre_ion: Precision specification
 * @siz: Size specifier
 *
 * Return: 1 or 2;
 */
int handling_print(const char *fmt, int *ind, va_list list, char buff[],
	int flag, int wid, int pre_ion, int siz)
{
	int n, unknow_leng = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_character}, {'s', print_str}, {'%', print_per},
		{'i', print_intger}, {'d', print_intger}, {'b', print_abinary},
		{'u', print_unsignednum}, {'o', printing_octal}, {'x', printing_hexadecimal}, {'X', printing_hexa_upper}, {'p', printing_pointer}, {'S', printing_non_printable},
		{'r', printing_reverse}, {'R', printing_rot13string}, {'\0', NULL}
	};
	for (n = 0; fmt_types[n].fmt != '\0'; n++)
		if (fmt[*ind] == fmt_types[n].fmt)
			return (fmt_types[n].fn(list, buff, flag, wid, pre_ion, siz));

	if (fmt_types[n].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_leng += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_leng += write(1, " ", 1);
		else if (wid)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_leng += write(1, &fmt[*ind], 1);
		return (unknow_leng);
	}
	return (printed_chars);
}
