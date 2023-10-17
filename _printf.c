#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{

	va_list argpn;
	va_start(argpn ,format);
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
            case 'd':
                count += fprintf(stdout, "%d", va_arg(argpn, int));
                break;
            case 'c':
                count += fprintf(stdout, "%c", va_arg(argpn, char));
                break;
            case 's':
                count += fprintf(stdout, "%s", va_arg(argpn, char *));
                break;
            case 'f':
                count += fprintf(stdout, "%f", va_arg(argpn, double));
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
	
	va_end(argpn);
	return count ;
	
}
