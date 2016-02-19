#include "my_functions.h"
#include <stdio.h>

void print_combination_2(void)
{
  int d1, d2, num;
  num = 0;
  for (d1=0; d1<9; d1++)
  {
    for (d2=0; d2<=9; d2++)
    {
      num++;
      if (d1 >= d2) {continue;}
      else
      {
	printf("%d%d", d1, d2);
      }
      if (num <= 89)
      {
	printf(", ");
      }
    }
  }
}
    
