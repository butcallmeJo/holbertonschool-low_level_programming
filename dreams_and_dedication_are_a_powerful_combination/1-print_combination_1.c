#include "my_functions.h"

void print_combination_1(void)
{
  int i;
  
  for (i=0; i<10; i++)
    {
      print_char(i+'0');
      if (i!=9)
	{
	  print_char(',');
	  print_char(' ');
	}    
    }
}
