#include <stdio.h>

int (*get_op_func(char c))(int, int);

int main(int argc, char *argv[]) {
  int i;
  char * op = argv[2];
  char * a = argv[1];
  char * b = argv[3];
  int (*op_func) (int, int);

  op_func = get_op_func(*op);
  i = op_func(atoi(a), atoi(b));
  printf("%d\n", i);
  return 0;
}
