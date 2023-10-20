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
	int count = 0;
 va_list args;
    va_start(args, format);

  
    while (*format != '\0')
    {
        if (*format != '%')
        {
            putchar(*format);
            count++;
        }
        else
        {
           
            switch (*++format)
            {
            case 'd':
                count += fprintf(stdout, "%d", va_arg(args, int));
                break;
            case 'c':
                count += fprintf(stdout, "%c", (char)va_arg(args, int));
		break;
            case 's':
                count += fprintf(stdout, "%s", va_arg(args, char *));
                break;
            case 'f':
                count += fprintf(stdout, "%f", va_arg(args, double));
                break;
            default:
                
                putchar('%');
                putchar(*format);
                count += 2;
                break;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}  
