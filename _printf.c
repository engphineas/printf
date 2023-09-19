#include "main.h"
#include <unistd.h>
/**
*_printf - The function produces output according to the format
* @format: format of character string
* Return: returns printed characters or -1 for error
*/
int _printf(const char *format, ...)
{
	va_list args;
	int length = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	length = printf_format_specifier(format, args);
	va_end(args);
	return (length);
}

/**
*write_handler-function to return a character
*@c:placeholder variable for a character
*Return: returns the printed character
**/
int write_handler(char c)
{
	return(write(1, &c, 1));
}
