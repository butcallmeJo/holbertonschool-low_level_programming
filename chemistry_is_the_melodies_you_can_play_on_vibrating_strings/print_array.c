#include <stdio.h>

void print_num(int n);
void print_negative(int n);

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
