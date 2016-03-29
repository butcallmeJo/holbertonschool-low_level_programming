#include <stdio.h>
int print_char(char c);

/*function that compares two strings*/
int strings_compare(char *s1, const char *s2)
{
  int i, r=0;
  for (i=0; *(s1+i)!='\0'; i++)
  {
    if ((*(s1+i))!=(*(s2+i)))
    {
      r=s1[i]-s2[i];
      break;
    }
  }
  return(r);
}
