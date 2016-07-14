#include <stdio.h>

/*prints each element of an array of integers.*/
void print_array(int *a, int n)
{
  int i;
  for (i=0; i<n; i++)
  {
    printf("%d", a[i]);
    if (i!=n-1) {printf(", ");}
    else {printf("\n");}
  }
}
