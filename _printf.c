#include "main.h"
/**
 * _printf - The function produces output according to the format
 * @format: format of character string
 * return: returns printed characters or -1 for error
 */
int _printf(const char *format, ...)
{
	int printed_char = 0;
	va_list chars_args;

	if (format == NULL)
		return (-1);
	va_start(chars_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_char++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				printed_char++;
			}
			else if (*format == 'c')
			{
				char character = va_arg(chars_args, int);

				write(1, &character, 1);
				printed_char++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(chars_args, char*);
				int length_string = 0;

				while (string[length_string] != '\0')
					length_string++;
				write(1, string, length_string);
				printed_char += length_string;
			}
		}
		format++;
	}
	va_end(chars_args);
	return (printed_char);
}
