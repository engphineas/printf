#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - The function produces output according to the format
 * @format: format of character string
 * Return: returns printed characters or -1 for error
 */
int _printf(const char *format, ...)
{
	int print_count = 0;
	va_list chars_args;

	if (format == NULL)
		return (-1);
	va_start(chars_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print_count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				print_count++;
			}
			else if (*format == 'c')
			{
				char s = va_arg(chars_args, int);

				write(1, &s, 1);
				print_count++;
			}
			else if (*format == 's')
			{
				char *z = va_arg(chars_args, char*);
				int length_z = 0;

				if (z == NULL)
					z = "(null)";
				while (z[length_z] != '\0')
					length_z++;
				write(1, &z, length_z);
				print_count += length_z;
			}
			else if (*format == 'i' || *format == 'd')
			{
				int fig = va_arg(chars_args, int);
				int length_fig = 0;
				char fig_str[12];

				snprintf(fig_str, sizeof(fig_str), "%d", fig);
				while (fig_str[length_fig] != '\0')
				{
					write(1, &fig_str[length_fig], 1);
					print_count++;
					length_fig++;
				}
			}
		}
		format++;
	}
	va_end(chars_args);
	return (print_count);
}
