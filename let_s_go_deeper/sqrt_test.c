#include <stdio.h>
int calculate_sqrt(int r, int n);

int square_root(int n)
{
  int r=1;
  return (calculate_sqrt(r, n));
}

int calculate_sqrt(int r, int n)
{
  if (r*r == n) {
    return r;
  }
  else if (r*r > n) {
    return -1;
  }
  else {
    r++;
    /*printf("%d ", r);*/
    calculate_sqrt(r, n);
  }
}

/*
printf("%d,     ", n);
printf("%d\n", r-1);
*/
