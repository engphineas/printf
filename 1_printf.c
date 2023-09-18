#include "main.h"
/**
*printing_char-function to print a character
* @types:args list
* @buffer:an array to handle print
* @flags:placeholder varaible for flags calculated
* @width:placeholder varaible for width
* @precision:placeholder variable for precision
* @size:placeholder varaible for size
* Return:returns total number of characters printed
**/
int printing_char(va_list types, char buffer[], int flags,
int width, int precision, int size) /*line broken cz was too long*/
{
char c;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

c = va_arg(types, int);

return (write(1, &c, 1));
}
/**
* printing_string - Prints a string
* @types:args list
* @buffer:an array to handle print
* @flags:placeholder varaible for flags calculated
* @width:placeholder varaible for width
* @precision:placeholder variable for precision
* @size:placeholder varaible for size
* Return:returns total number of characters printed
**/
int printing_string(va_list types, char buffer[], int flags,
int width, int precision, int size) /*line broken cz was too long*/
{
int length = 0, i;
char *str = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}

while (str[length] != '\0')
length++;

if (precision >= 0 && precision < length)
length = precision;

if (width > length)
{
if (flags & F_MIN)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}

return (write(1, str, length));
}
/**
*printing_percent - function to print the % sign
*@types:args list
*@buffer:an array to handle print
*@flags:placeholder varaible for flags calculated
*@width:placeholder varaible for width
*@precision:placeholder variable for precision
*@size:placeholder varaible for size
*Return:returns total number of characters printed
**/
int printing_percent(va_list types, char buffer[], int flags,
int width, int precision, int size)/*line broken cz was too long*/
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/*converting size number*/
/**
*size_number- function to cast a number to a specified size
*@num: placeholder of number to be casted
*@size: placeholder of size
*Return: the value casted
*/
long int size_number(long int n, int size)
{
if (size == _LONG)
	return (n);

else if (size == _SHORT)
	return ((short)n);
return ((int)n);
}


/**
*printing_binary - function to print binary
*@types: args list
*@buffer: an array to handle print
*@flags:  placeholder varaible for flags calculated
*@width: placeholder varaible for width
*@precision: placeholder variable for precision
*@size: placeholder varaible for size
*Return: returns total number of characters printed
**/
int printing_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)/*line broken cz was too long*/
{
unsigned int x, y, i, sum;
unsigned int a[32];
int count;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

x = va_arg(types, unsigned int);
y = 2147483648;/** unsigned int is a 32 bit datatum hence (2 ^ 31) - 1*/
a[0] = x / y;
for (i = 1; i < 32; i++)
{
y /= 2;
a[i] = (x / y) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];

write(1, &z, 1);
count++;
}
}
return (count);
}

