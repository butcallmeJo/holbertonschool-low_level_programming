#include "my_functions.h"
/* To get the function print_number */

/* The print_number function
 * that calls the print_char function
 * to print out the integer input
 * by parsing the input first.
 */
void print_number(int n)
{
  int q = n;
  int r = n;
  int x = 1;
  int p = q;
  /*char c = r;*/
  if (n == 0)
    {
      print_char('0');
    }
  else if (n > 0)
    {
      while (q != 0)
	{
	  p = q/10;
	  if (p != 0)
	    {
	      x = x*10;
	    }
	  q = p;
	}
      while (r/10 > 0)
	{
	  r = r/x;
	  r = r + '0';
	  print_char(r);
	  if ( x >= 10)
	    {
	      x = x/10;
	    }
	  
	}
    }
  else
    {
      while (q != 0)
        {
          p = q/10;
          if (p != 0)
            {
              x = x*10;
            }
          q = p;
        }
      while (r/10 < 0)
        {
          r = r/x;
          r = r + '0';
          print_char(r);
          if ( x >= 10)
            {
              x = x/10;
            }

        }
    }

}
