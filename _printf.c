#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
  va_list args;
    va_start(args, format);

    int char_count = 0; // To keep track of the number of characters printed

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            switch (*format) {
                case 'c':
                    // Handle %c specifier (character)
                    char c = va_arg(args, int); // Characters are promoted to int
                    putchar(c);
                    char_count++;
                    break;
                case 's':
                    // Handle %s specifier (string)
                    char *str = va_arg(args, char *);
                    fputs(str, stdout);
                    char_count += strlen(str);
                    break;
                case '%':
                    // Handle %% as a literal '%'
                    putchar('%');
                    char_count++;
                    break;
                default:
                    // Unsupported format specifier, print it as is
                    putchar('%');
                    char_count++;
                    putchar(*format);
                    char_count++;
            }
        } else {
            // Print characters that are not format specifiers
            putchar(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count; // Return the total number of characters printed
}
