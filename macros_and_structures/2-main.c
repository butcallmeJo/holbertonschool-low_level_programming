#include "str_struct.h"

struct String *string_to_struct(char *str);
void print_string_struct(struct String *str);
int print_char(char c);

int main(void)
{
  struct String *str;

  str = string_to_struct("Holbertons of fun");
  print_string_struct(str);
  str = string_to_struct("C is fun");
  print_string_struct(str);
  return (0);
}
