#include <stdlib.h>
#include "list.h"

int get_len(char *);
char *copy_string(char *);
int list_size(List *);
int add_node(List **list, char *str);

int insert_in_list(List **list, char *content, int index) {
  List *node;
  List *temp;
  List *new;
  int size = list_size(*list);
  int i = 0;

  if (index < 0) return 0;
  else if (index >= size || index == 0) {
    return (add_node(list, content));
  }
  else {
    node = *list;
    temp = *list;
    while (i < index) {
      temp = node;
      node = node->next;
      i++;
    }
    new = malloc(sizeof(List));
    if (new == NULL) return 1;
    new->str = copy_string(content); /*copy_string is a func in add_node*/
    new->next = node;
    temp->next = new;
    return 0;
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
