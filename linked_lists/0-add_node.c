#include <stdlib.h>
#include "list.h"

int get_len(char *);
char *copy_string(char *);

/*func to add node to a list at the begining of list*/
int add_node(List **list, char *content) {
  /*creates node*/
  List *node;
  /*init new str*/
  char * str;

  /*allocates mem to node so same size as List*/
  node = malloc(sizeof(List));
  /*error checking*/
  if (node == NULL) return (1);

  /*creates a cpy of content string to separate them in*/
  str = copy_string(content);
  node->str = str;
  node->next = *list;
  *list = node;
  return (0);
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
