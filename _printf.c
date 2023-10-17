#include <stdio.h>
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

 va_list list_args;

  int count_print = 0;

  if(format == NULL )
  {
	  return (-1);
  }

  va_start(list_args,format);
  
  while(*format)
  {
  if(*format != '%')
  {
  write(1, format ,1);
  count_print++;
  }
  else
  {
  format++;
  
if(*format == '\0')
{break;}

else if(*format == 'c')
{

char c = va_arg(list_args, int);
write (1,&c,1);
count_print++;
}

else if(*format == 's')
{
char *str = va_arg(list_args,char*);
int str_len = 0;

// calculate the lenght 
while (str[str_len] != '\0')
	str_len++;
write(1, str, str_len);
count_print += str_len;
}

  }

format++;

}

va_end(list_args);
return count_print;

}
