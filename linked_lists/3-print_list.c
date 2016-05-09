#include <stdlib.h>
#include "list.h"

int print_char(char c);
void print_element(char *str);
void print_list(List *list);

void print_list(List *list)
{
  List *node = list;
  while(node != NULL) {
    print_element(node->str);
    if(node->next != NULL) {
  	  print_char(',');
  	  print_char(' ');
  	}
    node = node->next;
  }
  print_char('\n');
}

void print_element(char *str)
{
  int i;
  for(i=0; str[i]!='\0'; i++) {
    print_char(str[i]);
  }
}
