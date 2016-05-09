#include <stdlib.h>
#include "list.h"

int list_size(List *list) {
  int i;
  List *node;
  node = list;
  while (node != NULL) {
    i++;
    node = node->next;
  }
  return i;
}
