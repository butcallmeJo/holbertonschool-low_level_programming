#include <stdio.h>

/*converts letter to uppercase if applicable*/
char uppercase(char c)
{
  if(c>=97 && c<=122)
  {
    c-= 32;
  }
  return(c);
}
