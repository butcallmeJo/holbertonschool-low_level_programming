#include "my_functions.h"

int str_len(char *s)
{
  int count;
  count=0;
  
  while (s[count]!='\0')
  {
    count++;
  }
  return(count);
}
