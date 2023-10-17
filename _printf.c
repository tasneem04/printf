#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Custom printf function supporting %c, %s, and %%
 * @format: Format string with optional format specifiers
 * @...: Additional arguments corresponding to the format specifiers
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...) 
{
 va_list args;
    va_start(args, format);

    int count = 0;
    while (*format != '\0')
    {
        if (*format != '%')
        {
            putchar(*format);
            count++;
        }
        else
        {
            // Handle format specifiers
            switch (*++format)
            {
           
            case 'c':
                count += fprintf(stdout, "%c", va_arg(args, char));
                break;
            case 's':
                count += fprintf(stdout, "%s", va_arg(args, char *));
              
             break;
            default:
                // Handle unknown format specifiers
                putchar('%');
                putchar(*format);
                count += 2;
                break;
            }
        }
        format++;
    }   
