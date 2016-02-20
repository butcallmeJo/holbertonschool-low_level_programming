#include <stdio.h>

/*prints numbers from 1-100 and replaces multiples of 3 by Fizz,
 *multiples of 5 by Fuzz and multiples of 3 and 5 by FizzBuzz */
int main(void)
{
  int n;
  for (n=1; n<=100; n++)
  {
    /*last number, no space after*/
    if (n==100)
    {
      printf("Buzz");
    }
    else if (n%5==0 && n%3==0)
    {
      printf("FizzBuzz ");
    }
    else if (n%3==0)
    {
      printf("Fizz ");
    }
    else if (n%5==0)
    {
      printf("Buzz ");
    }
    else
    {
      printf("%d ", n);
    }
  }
  return(0);
}
