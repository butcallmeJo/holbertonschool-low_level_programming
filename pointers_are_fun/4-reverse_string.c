#include "my_functions.h"
#include <stdio.h>

void reverse_string(char *s)
{
  int count, count2, count0;
  char temp;
  count = count2 = 0;
  temp='a';
  while (s[count]!='\0')
  {
    count++;
  }
  count2=count;
  count0=0;
  while (count>count2/2)
  {
    temp=s[count0];
    s[count0]=s[count-1];
    s[count-1]=temp;
    count--;
    count0++;
  }
}
