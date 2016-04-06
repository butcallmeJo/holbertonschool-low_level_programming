#include <stdio.h>

int add (int a, int b) {
  return a+b;
}

int add_char (char a, char b, int c) {
  return (int) (a + b + c);
}

int main () {
  int (* abc) (int, int); //pointer to a function that takes 2 int params and returns int
  int (* second) (char, char, int);
  abc = add;
  abc(1, 2);
  printf("%d\n", abc(1, 5));
}
