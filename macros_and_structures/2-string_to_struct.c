#include <stdlib.h>
#include "str_struct.h"

struct String *string_to_struct(char *str) {
  int i;
  struct String *str1;

  str1 = malloc(sizeof(struct String));
  if (str1 == NULL)
    return (NULL);

  for (i = 0; str[i] != 0; i++)

  str1->str = str;
  str1->length = i;
  return str1;
}
