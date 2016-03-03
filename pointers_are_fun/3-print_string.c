#include "my_functions.h"

void print_string(char *str)
{
  int count;
  for (count=0; str[count]!='\0'; count++)
  {
    print_char(str[count]);
  }
}
