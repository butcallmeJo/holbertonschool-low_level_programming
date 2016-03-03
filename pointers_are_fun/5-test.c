#include <stdio.h>
int string_to_integer(char *s);

int main(void)
{
  int n;

  n = string_to_integer("-98");
  printf("%d\n", n);
  n = string_to_integer("987");
  printf("%d\n", n);

  return (0);
}
