
int find_first_digit(int n)
{
  int power, ncopy;
  power = 1;

  for (ncopy=n; ncopy<-9;)
  {
    power = power*10;
    ncopy = ncopy/10;
  }

  n = n/power;
  return (-n);

}

int first_digit(int n)
{
  if (n==0)
  {
    return (n);
  }
  else if (n > 0)
  {
    n = find_first_digit(-n);
  }
  else if (n<0)
  {
    n = find_first_digit(n);
  }
  return (n);
}
