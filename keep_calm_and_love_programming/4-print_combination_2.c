#include "my_functions.h"
#include <stdio.h>

/*prints all possible combinations of 2 different digits*/
void print_combination_2(void)
{
  int d1, d2;
  for (d1=0; d1<9; d1++)
  {
    for (d2=d1+1; d2<=9; d2++)
    {
      printf("%d%d", d1, d2);
      /*last combinations are 79 and 89: so no comma after 80s*/
      if (d1<8)
      {
	printf(", ");
      }
    }
  }
}
    
