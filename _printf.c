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
 char token[1000];
 int k = 0, i;   
 va_list ptr;
    va_start(ptr, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        token[k++] = format[i];

        if (format[i + 1] == '%' || format[i + 1] == '\0')
       	{
            token[k] = '\0';
            k = 0;
            if (token[0] != '%')
	    {
                fprintf(stdout, "%s", token);
            } else {
                int j = 1;
                char ch1 = 0;

                while ((ch1 = token[j++]) < 58) {
                }
                if (ch1 == 'i' || ch1 == 'd' || ch1 == 'u' || ch1 == 'h')
	       	{
                    fprintf(stdout, token, va_arg(ptr, int));
                } else if (ch1 == 'c') {
                    fprintf(stdout, token, va_arg(ptr, int));
                } else if (ch1 == 'f') {
                    fprintf(stdout, token, va_arg(ptr, double));
                } else if (ch1 == 'l') {
                    char ch2 = token[2];
                    if (ch2 == 'u' || ch2 == 'd' || ch2 == 'i') {
                        fprintf(stdout, token, va_arg(ptr, long));
                    } else if (ch2 == 'f') {
                        fprintf(stdout, token, va_arg(ptr, double));
                    }
                } else if (ch1 == 'L') {
                    char ch2 = token[2];
                     if (ch2 == 'f') {
                        fprintf(stdout, token, va_arg(ptr, long double));
                    }
                } else if (ch1 == 's') {
                    fprintf(stdout, token, va_arg(ptr, char*));
                } else {
                    fprintf(stdout, "%s", token);
                }
            }
        }
    }

    va_end(ptr);
    return 0;
}	
