#include <stdio.h>

char uppercase(char c)
{
  if(c>=97 && c<=122)
  {
    c-= 32;
  }
  return(c);
}
