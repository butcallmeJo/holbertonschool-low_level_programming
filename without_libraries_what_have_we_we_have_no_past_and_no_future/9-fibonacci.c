#include <stdio.h>

/*prints the first 50 Fibonacci numbers, starting with 1 and 2,
 followed by a new line*/
int main(void)
{
  long n, fn, f1, f2;
  fn = 1;
  f1 = 1;
  f2 = 2;
  for (n=1; n<=50; n++)
  {
    if (n==50)
    {
      printf("%li\n", fn);
    }
    else
    {
      printf("%li, ", fn);
    }
    f1 = f2;
    f2 = fn+f2;
    fn = f1;
  }
  return(0);
}
