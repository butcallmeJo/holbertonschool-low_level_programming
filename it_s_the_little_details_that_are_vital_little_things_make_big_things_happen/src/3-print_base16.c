int print_char(char c);
/* The print_base16 function that calls
 * the print_char function in 2 loops
 * to print base 16 from 0 to F.
 */
void print_base16(void)
{
  char i = '0';
  char c = 'A';
  for (; i <= '9'; i++)
    {
      print_char(i);
    }
  for (; c <= 'F'; c++)
    {
      print_char(c);
    }
}
