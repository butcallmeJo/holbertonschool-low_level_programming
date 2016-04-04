#include <stdio.h>

int main(int argc, char  **argv) {
  argc--;
  printf ("%d\n", argc);
  argv++;
  return 0;
}
