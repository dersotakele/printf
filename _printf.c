#include "main.h"

void print_buffer(char buff[], int *buff_ind);

/**
 *  _printf - Printf function
 *  @format: format.
 *  Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int n, printing = 0, printing_characters = 0;
	int flag, wid, pre_ion, siz, buff_ind = 0;
	va_list list;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buff[buff_ind++] = format[n];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buff, &buff_ind);
			/* write(1, &format[i], 1);*/
			printing_characters++;
		}
		else
		{
			print_buffer(buff, &buff_ind);
			flag = geting_flags(format, &n);
			wid = geting_width(format, &n, list);
			pre_ion = geting_precision(format, &n, list);
			siz = geting_size(format, &n);
			++n;
			printing = handling_print(format, &n, list, buff,
				flag, wid, pre_ion, siz);
			if (printing == -1)
				return (-1);
			printing_characters += printing;
		}
	}

	print_buffer(buff, &buff_ind);

	va_end(list);

	return (printing_characters);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buff: Array of char
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buff[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buff[0], *buff_ind);

	*buff_ind = 0;
}
