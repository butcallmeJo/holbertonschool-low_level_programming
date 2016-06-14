#include <unistd.h>
int printf(const char *format, ...);
int print_char(char);

int print_char(char c)
{
   return (write(1, &c, 1));
}
