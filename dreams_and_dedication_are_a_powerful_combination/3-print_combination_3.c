/* My_functions.h contains all functions used in all files in this directory */
#include "my_functions.h"

/* prints all possible combinations of 3 different digits using 3 loops */
void print_combination_3(void)
{
  int d1, d2, d3, num;
  for (d1=0; d1<9; d1++)
    {
      for (d2=0; d2<=9; d2++)
        {
	  if (d1 >= d2) 
	    {
	      continue;
	    }
	  for (d3=0; d3<=9; d3++)
	    {
	      if (d2 >= d3) {continue;}
	      else
		{
		  print_char(d1+'0');
		  print_char(d2+'0');
		  print_char(d3+'0');
		}
	      num = d1*100 + d2*10 + d3*10;
	      if (num < 789)
		{
		  print_char(',');
		  print_char(' ');
		}
	    }
        }
    }
}


/*


 */
