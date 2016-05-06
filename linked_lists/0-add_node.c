#include <stdlib.h>
#include "list.h"

int get_len(char *);
char *copy_string(char *);

int add_node(List **list, char *content) {
  List *node;
  char * str;
  node = malloc(sizeof(List));
  if (node == NULL) return (1);
  str = copy_string(content);
  node->str = str;
  node->next = *list;
  *list = node;
  return (0);
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
