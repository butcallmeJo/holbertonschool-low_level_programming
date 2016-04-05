void swap_int(int *a, int *b)
{
  int a2, b2;
  a2 = *a;
  b2 = *b;

  *a = b2;
  *b = a2;
}
