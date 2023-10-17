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
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count = 0; // To keep track of the number of characters printed

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    write(1, &c, 1); // Print character
                    char_count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str) {
                        write(1, str, 1); // Print each character in the string
                        str++;
                        char_count++;
                    }
                    break;
                }
                case '%':
                    write(1, "%", 1); // Print a literal '%'
                    char_count++;
                    break;
                default:
                    write(1, "%", 1); // Print the '%' and the unsupported character
                    char_count++;
                    write(1, format, 1);
                    char_count++;
            }
        } else {
            write(1, format, 1); // Print characters that are not format specifiers
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count; // Return the total number of characters printed
}
