/* My_functions.h contains all functions used in all files in this directory */
#include "my_functions.h"

/* prints all possible combinations of 2 different digits */
void print_combination_2(void)
{
  int d1, d2, num;
  num = -1;
  for (d1=0; d1<9; d1++)
    {
      for (d2=0; d2<=9; d2++)
	{
	  num++;
	  if (d1 >= d2) {continue;}
	  else
	    {
	      print_char(d1+'0');
	      print_char(d2+'0');
	    }
	  if (num < 89)
	    {
	      print_char(',');
	      print_char(' ');
	    }
	}
    }

}


/*

Nums  01, 02, 03, 04, 05, 06, 07, 08, 09, 12

  LOOP: num=0; until num=99; num++
  {
    if num < 10
    {
      print_num(0)
      print_num(num)
    }
    else
    {
      print_num(num)
    }  

*/

/*
OR OR OR OR OR
*/

/*
  LOOP: n1=0; while n1<9; n1++

    LOOP: n2=0; while n2<=9; n2++

      if n1 >= n2
        continue
      else
        print_char n1
	print_char n2

*/
