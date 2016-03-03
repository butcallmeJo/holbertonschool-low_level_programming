#include "my_functions.h"

void reverse_string(char *s)
{
  int count, count2;
  char scopy[30];
  count=0;
  count2=0;
  while (s[count]!='\0')
  {
    count++;
  }
  while (count2<count)
  {
    scopy[count2] = s[count2];
    count2++;
  }
  count2=0;
  while (count>0)
  {
    s[count2]=scopy[count-1];
    count--;
    count2++;
  }
}
