int print_char(char c);

/* prints an integer from a negative integer without using the std library */
void print_negative(int n)
{
  int digits, power, ncopy, nless;
  char charout;
  power = 1;
  ncopy = n;
  nless = n;
  
  /* to figure out the number of digits and the 10^digit of the int */
  for (digits=0; ncopy != 0; digits++)
  {
    ncopy = ncopy/10;
    power = power*10;
  }
  /* power needs to be 10 times smaller. & re-initializing ncopy */
  power = power / 10;
  ncopy = n;
  /* prints the int, char by char */
  for (; digits > 0; digits--)
  {
    ncopy = nless/power;
    charout = ncopy*-1+'0';
    nless = nless%power;
    power = power/10;
    print_char(charout);
  }
}

/* prints any integer without using the std library */
void print_number(int n)
{
  int ncopy = n;

  if (n == 0)
  {
    print_char('0');
  }
  /* flipping the sign of ncopy if n is positive 
     to account for the negative limit of int*/
  else if (n > 0)
  {
    ncopy = n * -1;
    print_negative(ncopy);
  }
  else
  {
    print_char('-');
    print_negative(ncopy);
  }
}
