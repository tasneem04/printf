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
		    case 'b':
		    {
                    unsigned int num = va_arg(args, unsigned int);
                    char binary_str[33];
		    int i;
                    for ( i = 31; i >= 0; i--) {
                        binary_str[31 - i] = (num & (1 << i)) ? '1' : '0';
                    }
                    binary_str[32] = '\0';
                    write(1, binary_str, 32);
                    char_count += 32;
                    break;
                }
		     case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    char num_str[20];
                    int length = sprintf(num_str, "%u", num);
                    write(1, num_str, length);
                    char_count += length;
                    break;
                }
                case 'o': {
                    unsigned int num = va_arg(args, unsigned int);
                    char num_str[20];
                    int length = sprintf(num_str, "%o", num);
                    write(1, num_str, length);
                    char_count += length;
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(args, unsigned int);
                    char num_str[20];
                    int length = sprintf(num_str, "%x", num);
                    write(1, num_str, length);
                    char_count += length;
                    break;
                }
                case 'X': {
                    unsigned int num = va_arg(args, unsigned int);
                    char num_str[20];
                    int length = sprintf(num_str, "%X", num);
                    write(1, num_str, length);
                    char_count += length;
                    break;
                }
		 case 'p':
			  {
                    void *ptr = va_arg(args, void *);
                    char ptr_str[20];
                    int length = sprintf(ptr_str, "%p", ptr);
                    write(1, ptr_str, length);
                    char_count += length;
                    break;
                }

		case 'r': 
		 {
                    char *str = va_arg(args, char *);
                    int length = strlen(str);
                    for (int i = length - 1; i >= 0; i--) {
                        write(1, &str[i], 1);
                        char_count++;
                    }
                    break;

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
 
