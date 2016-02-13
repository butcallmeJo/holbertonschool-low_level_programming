/* My_functions.h contains all functions used in all files in this directory */
#include "my_functions.h"

/* prints all combinations of single-digit numbers */
void print_combination_1(void)
{
  int i;
  
  for (i=0; i<10; i++)
    {
      print_char(i+'0');
      /* We don't want to print a comma and a space after the last digit */
      if (i!=9)
	{
	  print_char(',');
	  print_char(' ');
	}    
    }
}
