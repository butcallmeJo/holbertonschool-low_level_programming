#include <stdlib.h>
#include "str_struct.h"

char *copy_string(char *);
int get_len(char *);

struct String *string_to_struct(char *str) {
  int i;
  char *cpy = copy_string(str);
  struct String *str1;

  str1 = malloc(sizeof(struct String));
  if (str1 == NULL)
    return (NULL);

  for (i = 0; str[i] != 0; i++) {}

  str1->str = cpy;
  str1->length = i;
  return str1;
}

int get_len(char * str) {
  int len;
  for (len = 0; str[len] != 0; len++) {}
  return len;
}

char *copy_string(char *str) {
  int len = get_len(str);
  char *new_str = malloc(sizeof(char *) * len+1);
  char *cpy_str = new_str;
  while (*str != 0) {
    *cpy_str = *str;
    cpy_str++;
    str++;
  }
  return new_str;
}
