#include"main.h"
#include <stdlib.h>

/**
*printf_format_specifier-main function
*@format:placeholder for the formats to print
*@char_args:placeholder for args
*Return:The length of the format
*/
int printf_format_specifier(const char *format, va_list char_args)
{
	int printed_char = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			i++;

			while (format[i] == ' ')
				i++;

			if (format[i] == '%')
				printed_char += write_handler(format[i]);
			if (check_char(format[i]) == 0)
			{
				printed_char += check_specifier(format[i - 1], format[i], printed_char);
			}
			else
			{
				printed_char += specifier(format[i], char_args);
			}
		}
		else
		{
			printed_char += write_handler(format[i]);
		}

		i++;
	}

	return (printed_char);
}

/**
*specifier - Prints a valid specifier
*@format: The specifier to prints
*@args: A list of variadic arguments
*Return: The length of the specifier
*/
int specifier(char format, va_list args)
{
	int i  = 0, length = 0;
	fmt_spec data[] = {
		{"c", character},
		{"s", string},
		{"d", integer},
		{"i", integer},
		{NULL, NULL}
	};

	while (data[i]._specifier)
	{
		if (*data[i]._specifier == format)
			length = data[i].function(args);

		i++;
	}

	return (length);
}


/**
*check_char-function to check type of specifier
*@specified_char:placeholder for type of specifiier to be checked
* Return: returns char type or error(0)
*/
int check_char(char specified_char)
{
	char char_type[] = {'c', 's', 'd', 'i', '%'};
	int i = 0;

	while (char_type[i])
	{
		if (char_type[i] == specified_char)
			return (1);
		i++;
	}
	return (0);
}
/**
*check_specifier-function to check for an invalid specifier
*@char_intial: placeholder specifier
*@format: placeholder format
*@length: placeholder for number of charcters befor an invalid xter
*Return: the number of characters after printing invalid xter
*/
int check_specifier(char char_initial, char format, int length)
{
	length += write_handler('%');

	if (char_initial == ' ')
	{
		length += write_handler(' ');
		length += write_handler(format);
	}
	else
	{
		length += write_handler(format);
	}

	return (length);
}
