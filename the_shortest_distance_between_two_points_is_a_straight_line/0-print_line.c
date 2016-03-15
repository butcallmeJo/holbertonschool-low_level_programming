int print_char(char c);

void print_line(int n)
{
  int i;
  if (n <= 0) {print_char('\n');}
  else
  {
    for (i=0; i<n; i++){print_char('_');}
    print_char('\n');
  }
}
