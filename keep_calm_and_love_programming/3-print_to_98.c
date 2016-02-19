#include <stdio.h>

void print_to_98(int n)
{
  if (n==98)
  {
    printf("98\n");
  }
  else if (n>98)
  {
    while (n>=98)
    {
      printf("%d", n);
      n--;
      if (n>=98)
      {
	printf(", ");
      }
    }
    printf("\n");
  }
  else
  {
    while (n<=98)
    {
      printf("%d", n);
      n++;
      if (n<=98)
      {
	printf(", ");
      }

    }
    printf("\n");
  }
}
