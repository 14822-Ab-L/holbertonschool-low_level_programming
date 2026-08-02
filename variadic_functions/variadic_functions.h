#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * struct print_format - structure for format specifiers
 * @type: format character
 * @f: function associated with format
 */
typedef struct print_format
{
	char *type;
	void (*f)(va_list);
} print_format;

void print_char(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void print_string(va_list args);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif                                                                                                          
~                                                                                                                                                                                                                                      
~                                                                                                                                    
