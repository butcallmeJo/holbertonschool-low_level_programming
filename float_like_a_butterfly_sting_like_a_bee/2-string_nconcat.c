#include <stdio.h>
#include <stdlib.h>

char *string_nconcat(char *s1, char *s2, int n) {
  char *str;
  unsigned int i, size1, size2;
  for (size1=0; s1[size1]!=0; size1++) {}
  for (size2=0; s2[size2]!=0; size2++) {}
  str = malloc(size1+n+1);
  if (str == NULL) {
    return NULL;
  }
  for (i=0; i<size1; i++) {
    /* looping over s1 */
    str[i] = *(s1+i);
  }
  for (i=0; i<size2 && i<(unsigned)n; i++) {
    /* looping over s2 */
    str[size1+i] = *(s2+i);
  }
  str[size1+n+1] = '\0';
  if (str == NULL) {
    return NULL;
  }
  return str;
}
