int print_char(char c);
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
