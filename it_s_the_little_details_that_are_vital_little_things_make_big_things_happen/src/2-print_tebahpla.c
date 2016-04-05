int print_char(char c);

/* The print_tebahpla function that calls
 * the print_char function in a while loop
 * to print the alphabet in reverse.
 */
void print_tebahpla(void)
{
  char c = 'z';
  while (c >= 'a')
    {
      print_char(c);
      c--;
    }
}
