int print_char(char c);

/*function to print the second half of the string*/
void print_string_half(char *str)
{
  int i, h=0;

  /*loop to find the length of the array*/
  for (i = 0; str[i] != '\0'; i++) {}

  /*setting the halfway point depending on even or odd i*/
  if (i%2==0) {h=i/2;}
  else {h=(i/2)+1;}

  /*loop to print the chars starting at the halfway point*/
  for (; h<i; h++)
  {
    print_char(str[h]);
  }
}
