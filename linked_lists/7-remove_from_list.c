#include <stdlib.h>
#include "list.h"

int get_len(char *);
char *copy_string(char *);
int list_size(List *);

void remove_from_list(List **list, int index) {
  List *node;
  List *before;
  List *after;
  int size = list_size(*list);
  int i = 0;
  node = *list;

  if (index == 0) {
    *list = node->next;
  }
  else if (index <size) {
    while (i < index) {
      before = node;
      after = node->next;
      node = node->next;
      i++;
    }
    before->next = after->next;
    free(node->str);
    free(node);
  }
}

int list_size(List *list) {
  List *node;
  int size;
  node = list;
  size = 0;

  while (node != NULL) {
    size++;
    node = node->next;
  }
  return size;
}
