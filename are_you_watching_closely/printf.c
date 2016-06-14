/* recodes printf fuction from standard library */
#include <unistd.h>
#include <stdarg.h>

int print_char(char);

int	my_printf(const char *format, ...)
{
  va_list	arg;
  int	a;

  va_start(arg, format);
  a = 0;
  while (format[a] != '\0')
    {
	  print_char(format[a]);
	  a = a + 1;
    }
  va_end(arg);
  return a;
}

int print_char(char c)
{
   return (write(1, &c, 1));
}
