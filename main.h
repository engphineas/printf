#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>
/**
*fomart_specifiers-function struct
*@_specifier:specifier
*@function:function
**/
typedef struct fomart_specifiers
{
char *_specifier;
int (*function)(va_list args);
}fmt_spec;
int write_handler(char c);
int _printf(const char *format, ...);
int printf(const char *format, ...);
int _print_format(const char *format, va_list args);
int printf_format_specifier(const char *format, va_list char_args);
int specifier(char format, va_list args);
int integer(va_list args);
int string(va_list char_args);
int character(va_list int_args);
int check_specifier(char char_initial, char format, int length);
int check_char(char specified_char);
#endif
