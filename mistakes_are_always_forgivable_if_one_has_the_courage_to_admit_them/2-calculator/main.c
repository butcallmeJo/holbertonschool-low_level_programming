#include <stdlib.h>
#include <stdio.h>
#include "calculator.h"

int main(int argc, char *argv[]) {
  int i;
  char * op = argv[2];
  char * a = argv[1];
  char * b = argv[3];
  int (*op_func) (int, int);

  /*checking to see number of arguments are correct*/
  if (argc != 4) {
    return 1;
  }
  op_func = get_op_func(*op);
  /*checking if operator is correct*/
  if (op_func == 0) {return 1;}
  i = op_func(atoi(a), atoi(b));
  print_number(i);
  print_char('\n');
  return 0;
}
