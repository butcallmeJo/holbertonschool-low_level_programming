#include <limits.h>
#include <stdio.h>

/*takes an int and returns the absolute value of said int*/
int absolute(int n)
{
  if(n<0)
  {
    n = n*-1;
  }
  return(n);
}
