#include "main.h"

/**
 * geting_flags - a function that  Calculate active flags
 * @format: Formatin a string in which to print the arguments
 * @n: taking a parameter.
 *
 * Return: Flags:
 */
int geting_flags(const char *format, int *n)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int m, cur_n;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_n = *n + 1; format[cur_n] != '\0'; cur_n++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (format[cur_n] == FLAGS_CH[m])
			{
				flag |= FLAGS_ARR[m];
				break;
			}

		if (FLAGS_CH[m] == 0)
			break;
	}
	*n = cur_n - 1;

	return (flag);
}
