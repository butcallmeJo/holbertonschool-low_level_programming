#include <stdio.h>

int string_to_integer(char *s)
{
  int count, sign, boolean;
  long num;
  count = num = 0;
  sign = boolean = 1;
  while (s[count]!='\0') 
  {
    if (s[count] <'0' || s[count]>'9')
    {
      if (s[count]=='-') {sign*=-1;}
      if (boolean==0) {break;}
    }
    if (s[count] >='0' && s[count]<='9')
    {
      num = 10 * num + (s[count]-48);
      boolean = 0;
    }
    count++;
  }  
  num = sign*num;
  if (num > 2147483647 || num < -2147483648) {num=0;}
  return((int)num);
}
