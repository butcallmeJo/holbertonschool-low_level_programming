int print_char(char c);

/*function to print the second half of the string*/
void print_string_half(char *str)
{
  int i, c;
  for (i = 0; str[i] != '\0'; i++) {}
  for (c=(i/2)+1; c<i; c++)
  {
    print_char(str[c]);
  }
}
