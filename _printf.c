#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function supporting %c, %s, and %%
 * @format: Format string with optional format specifiers
 * @...: Additional arguments corresponding to the format specifiers
 *
 * Return: The number of characters print
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') 
	{
            format++;
            switch (*format) 
	    {
                case 'c':
		       	{
                    char c = va_arg(args, int);
                    write(1, &c, 1);
                    char_count++;
                    break;
                }
                case 's':
		       	{
                    char *str = va_arg(args, char *);
                    while (*str) {
                        write(1, str, 1);
                        str++;
                        char_count++;
                    }
                    break;
                }
                case '%':
                    write(1, "%", 1);
                    char_count++;
                    break;
                case 'd':
                case 'i': 
		    {
                    int num = va_arg(args, int);
                    char num_str[20];
                    int length = sprintf(num_str, "%d", num);
                    write(1, num_str, length);
                    char_count += length;
                    break;
                }
                default:
                    write(1, "%", 1);
                    char_count++;
                    write(1, format, 1);
                    char_count++;
            }
        } else 
	{
            write(1, format, 1);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count; 
}
 
