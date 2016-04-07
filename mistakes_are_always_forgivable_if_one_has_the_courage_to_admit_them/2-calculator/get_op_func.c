#include "calculator.h"

int (*get_op_func(char c))(int, int) {
  int (*func_ptr_array[256])(int, int);
  func_ptr_array[37] = op_mod;
  func_ptr_array[42] = op_mul;
  func_ptr_array[43] = op_add;
  func_ptr_array[45] = op_sub;
  func_ptr_array[47] = op_div;

  if (c != 37 && c != 42 && c != 43 && c != 45 && c != 47) {
    return 0;
  }
  return func_ptr_array[c];
}
