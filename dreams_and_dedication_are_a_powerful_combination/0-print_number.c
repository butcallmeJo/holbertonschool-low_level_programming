#include "my_functions.h"
#include <unistd.h>
#include <stdio.h>

void print_positive(int n)
{
  int digits = 1;
  int power = 1;
  int ncopy = n;
  char charout;
  int nless = n;

  for (; ncopy != 0; digits++)
    {
      ncopy = ncopy/10;
      power = power*10;
    }

  digits--;
  power = power / 10;
  ncopy = n;

  for (; digits > 0; digits--)
    {
      ncopy = nless/power;
      charout = ncopy+'0';
      nless = nless%power;
      power = power/10;
      print_char(charout);
    }
}

void print_number(int n)
{
  int ncopy = n;

  if (n == 0)
    {
      print_char('0');
    }
  else if (n < 0)
    {
      ncopy = n * -1;
      print_char('-');
      print_positive(ncopy);
    }
  else
    {
      print_positive(ncopy);
    }

}
/*
void main(void)
{
  print_number(1024);
  print_number(123456789);
  print_number(0);
  print_number(-524);
}
*/

/*
  
  4123
  412
  41
  4
  0
  
 */
