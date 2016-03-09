int print_char(char c);

/*function to print one character out of 2, starting with the 1st one*/
void print_string_2(char *str)
{
  int c;
  for (c=0; str[c]!='\0'; c++)
  {
    if (c%2 == 0)
    {
    print_char(str[c]);
    }
  }
}
