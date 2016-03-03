#include <stdio.h>

int string_to_integer(char *s)
{
  int count, start, end, sign, num, len, power;
  count = start = end = num = len = 0;
  sign = power = 1;

  while (s[count]!='\0' && (s[count] <'0' || s[count]>'9'))
  {
    if (s[count]=='-')
    {
      sign *= -1;
    }
    count++;
    start++;
  }
  end = start;

  while (s[count]!='\0' && (s[count] >='0' && s[count]<='9'))
  {
    count++;
    end++;
  }

  len = end-start;
  while (len>0)
  {
    power = power * 10;
    len--;
  }
  power = power/10;
  count = start;

  while (power>0)
  {
    num = 10*num + (s[count]-48);
    power = power / 10;
    count++;
  }
  num*=sign;
  return(num);
}
