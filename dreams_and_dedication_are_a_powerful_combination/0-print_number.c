#include "my_functions.h"
#include <unistd.h>
#include <stdio.h>

int print_char(char c);

void print_number(int n)
{
  int digits = 1;
  int power = 1;
  int ncopy = n;
  
  if (n == 0)
    {
      /*print_char('0');*/
    }
  else if (n < 0)
    {
      ncopy = n * -1;
    }
  
  for (; ncopy != 0; digits++)
    {
      ncopy = ncopy/10;
      power = power*10;
    }
  digits--;
  power = power / 10;
  printf("%d \n", digits);
  printf("%d \n", power);

}

void main(void)
{
  print_number(98);
  print_number(2);
}
/*
  
  4123
  412
  41
  4
  0
  
 */
