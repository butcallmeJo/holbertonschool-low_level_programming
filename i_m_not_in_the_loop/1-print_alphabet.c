#include "my_functions.h"
/* To get the function print_alphabet */

/* The print_alphabet function that calls
 * the print_char function in a while loop
 * to print the alphabet.
 */
void print_alphabet(void)
{
  char c = 'a';
  while (c <= 'z')
    {
      print_char(c);
      c++;
    }
}
