#include <stdio.h>

/*converts uppercase letter to lowercase*/
char lowercase(char c)
{
  if (c>='A' && c<='Z')
  {
    c+=32;
  }
  return(c);
}
