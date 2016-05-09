#include <stdlib.h>
#include "list.h"

int get_len(char *);
char *copy_string(char *);

/*func to add node to a list at the begining of list*/
int add_node(List **list, char *content) {
  /*creates node and head of node*/
  List *head;
  List *node;
  head = *list;

  /*creating the first node if none exists*/
  if (head == NULL) {
    head = malloc(sizeof(List));
    if(head == NULL) return(1);
    else {
      head->str = copy_string(content);
      head->next = NULL;
      *list = head;
      return (0);
    }
  }
  /*else add a node*/
  else {
    node = *list;
    while (node->next!=NULL) {
      node = node->next;
    }
    node->next = malloc(sizeof(List));
    if (node->next == NULL) return(1);
    else {
      node->next->str = copy_string(content);
      node->next->next = NULL;
      return(0);
    }
  }
  return (1);
}

/*func that gets the length of the string in parameter*/
int get_len(char * str) {
  int len;
  for (len = 0; str[len] != 0; len++) {}
  return len;
}

/*func that creates a cpy of the string passed as parameter*/
char *copy_string(char *str) {
  /*gets the length of str*/
  int len = get_len(str);
  /*allocates mem for new_str*/
  char *new_str = malloc(sizeof(char *) * len+1);
  /*cpy_str is of same size as str*/
  char *cpy_str = new_str;
  /*copies str to cpy_str*/
  while (*str != 0) {
    *cpy_str = *str;
    cpy_str++;
    str++;
  }
  return new_str;
}
