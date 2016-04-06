int main(int argc, char const *argv[]) {
  op = argv[3];
  a = argv[2];
  b = argv[4];

  get_op_func(op)(a, b);
  return 0;
}
