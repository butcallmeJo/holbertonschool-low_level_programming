#include <unistd.h>
#include <stdio.h>

int print_char(char c);

void find_last_negative(int n)
{
  int digits, ncopy;
  ncopy = n;
  
  for (digits=1; ncopy!=0; digits++)
  {
    ncopy = ncopy/10;
  }
  /*print_char((n%digits)+'0');*/
  printf("%d", digits);
  
}
