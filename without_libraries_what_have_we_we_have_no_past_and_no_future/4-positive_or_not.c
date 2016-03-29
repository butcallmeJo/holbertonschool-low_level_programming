#include "my_functions.h"
/* To get the function positive_or_not */

/* The positive_or_not function
 * that calls the print_char function
 * after checking that the input is
 * positive, negative or equal to 0.
 */
void positive_or_not(int n)
{
  if (n < 0)
    {
      print_char('N');
    }
  if (n == 0)
    {
      print_char('Z');
    }
  if (n > 0)
    {
      print_char('P');
    }
}
