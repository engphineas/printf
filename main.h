#ifndef MAIN_H
#define MAIN_H
#define UNUSED(x) (void)(x)
#define F_MIN 1
#define BUFFER_SIZE 1024
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>
int _printf(const char *format, ...);
int print_binary(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);



#endif
