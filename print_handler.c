#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
*character-function to print a char
*@int_args: placeholder variable for args
*Return: returns length of char
**/
int character(va_list int_args)
{
	write_handler(va_arg(int_args, int));
	return (1);
}

/**
*string-function to print a string
*@char_args: A list of variadic arguments
*Return: returns length of string
*/
int string(va_list char_args)
{
	char *c = va_arg(char_args, char *);
	int i = 0;

	if (c != NULL)
	{
		while (c[i])
		{
			write_handler(c[i]);
			i++;
		}

		return (i);
	}

	return (-1);
}
