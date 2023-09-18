#ifndef MAIN_H
#define MAIN_H
#define UNUSED(i) (void)(i)
#define F_MIN 1
#define BUFFER_SIZE 1024
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>
int _printf(const char *format, ...);
int printing_binary(va_list types, char buffer[], int flags,
int width, int precision, int size);
int printing_int(va_list types, char buffer[], int flags,
int width, int precision, int size);
int printing_string(va_list types, char buffer[], int flags,
int width, int precision, int size);
int printing_char(va_list types, char buffer[], int flags,
int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);


#endif
