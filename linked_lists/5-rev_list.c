
#include <stdlib.h>
#include "list.h"

void rev_list(List **list) {
  List *temp;
  List *first;
  List *second;

  first = *list;
  second = first->next;

  if (first != NULL && first->next != NULL) {
    first->next = NULL;
    while (first != NULL && second != NULL) {
      temp = second->next;
      second->next = first;
      first = second;
      if (temp != NULL) {
        second = temp;
      }
      else break;
    }
    *list = second;
  }
}
