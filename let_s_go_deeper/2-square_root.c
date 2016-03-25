int calculate_sqrt(int n, int i, int c);

int square_root(int n)
{
  int i=1, c=0;
  if (n<=0) return -1;
  return (calculate_sqrt(n, i, c));
}

int calculate_sqrt(int n, int i, int c)
{
  if (n < 0) return -1;
  else if (n==0) return c;
  else {
    n-=i;
    i+=2;
    c++;
    return calculate_sqrt(n, i, c);
  }
}
