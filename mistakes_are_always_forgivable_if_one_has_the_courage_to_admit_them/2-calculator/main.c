#include "calculator.h"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    print_char('X');
    print_char('\n');
    return 1;
  }
  int i;
  char * op = argv[2];
  char * a = argv[1];
  char * b = argv[3];
  int (*op_func) (int, int);

  op_func = get_op_func(*op);
  i = op_func(atoi(a), atoi(b));
  print_number(i);
  print_char('\n');
  return 0;
}
