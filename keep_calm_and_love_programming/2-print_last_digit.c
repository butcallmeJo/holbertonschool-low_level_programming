#include <unistd.h>
#include "my_functions.h"

/*prints the last digit of a given integer*/
void print_last_digit(int n)
{
  int lastdigit;
  
  if (n<0)
  {
    n = n*-1;
  }
  lastdigit = n%10;
  print_char(lastdigit+'0');
}
