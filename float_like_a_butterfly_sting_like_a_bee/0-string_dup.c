#include <stdio.h>
#include <stdlib.h>

char *string_dup(char *str){
  char *s;
  unsigned int i, size;
  for (size=0; str[size]!=0; size++) {}
  s = malloc(size+1);
  for (i=0; i<size+1; i++) {
    /* looping over str */
    s[i] = *(str+i);
  }
  if (s == NULL) {
    return NULL;
  }
  return s;
}
