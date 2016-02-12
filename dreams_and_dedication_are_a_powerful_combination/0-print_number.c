#include "my_functions.h"

void print_positive(int n)
{
  int digits, power, ncopy, nless;
  char charout;
  power = 1;
  ncopy = n;
  nless = n;
  
  for (digits=0; ncopy != 0; digits++)
    {
      ncopy = ncopy/10;
      power = power*10;
    }
  power = power / 10;
  ncopy = n;
  for (; digits > 0; digits--)
    {
      ncopy = nless/power;
      charout = ncopy*-1+'0';
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
  else if (n > 0)
    {
      ncopy = n * -1;
      print_positive(ncopy);
    }
  else
    {
      print_char('-');
      print_positive(ncopy);
    }

}
